#include <gtest/gtest.h>
#include <QList>
#include <QString>
#include <request/ODataURLParser.h>
#include <model/ODataModel.h>
#include <ODataTestEntitySet.h>
#include <ODataTestEntitySet2.h>
#include <request/odatarequesthandler.h>
#include <QtXml>


ODataRequestHandler * setupHandler(){

	char *args;
	int argc = 0;
	QCoreApplication *a = new QCoreApplication(argc, &args);

	ODataEntityContainer *entityContainer1 = new ODataEntityContainer();
	ODataSchema *schema1 = new ODataSchema("Test", entityContainer1);

	entityContainer1->entitySets.insert("TestEntitySet",
			new ODataTestEntitySet());

	ODataEntityContainer *entityContainer2 = new ODataEntityContainer();
	ODataSchema *schema2 = new ODataSchema("Test2", entityContainer2);
	entityContainer2->entitySets.insert("TestEntity2Set",
			new ODataTestEntitySet2());
	auto schemas = QMap<QString, ODataSchema*>( { { "Test", schema1 }, {
			"Test2", schema2 } });
	return new ODataRequestHandler(
			"https://localhost:8000", "/odata/", schemas);
}

TEST(ODataEntityPluginTest, addsAllEntitiesOfPlugins) {
	try {
		char *args;
		int argc = 0;
		QCoreApplication *a = new QCoreApplication(argc, &args);
		ODataEntityContainer *entityContainer1 = new ODataEntityContainer();
		ODataSchema *schema1 = new ODataSchema("Test", entityContainer1);

		entityContainer1->entitySets.insert("TestEntitySet",
				new ODataTestEntitySet());

		ODataEntityContainer *entityContainer2 = new ODataEntityContainer();
		ODataSchema *schema2 = new ODataSchema("Test2", entityContainer2);
		entityContainer2->entitySets.insert("TestEntity2Set",
				new ODataTestEntitySet2());
		auto schemas = QMap<QString, ODataSchema*>( { { "Test", schema1 }, {
				"Test2", schema2 } });
		ODataModel *model = new ODataModel("https://localhost:8000/", "/odata/",
				schemas);
		auto entities = model->getEntitySets();

		EXPECT_EQ(entities.count(), 2);
		EXPECT_TRUE(entities.contains("Test.TestEntitySet"));
		EXPECT_TRUE(
				entities["Test.TestEntitySet"]->getName() == "TestEntitySet");
	} catch (std::exception *ex) {
		std::cout << ex->what();
	}
}

TEST(ODataEntityPluginTest, returnServiceDocumentforAllEntities) {
	try {
		ODataRequestHandler * handler = setupHandler();
		QVariant result = handler->handleRequest(
				QUrl("https://localhost:8000/odata/"), QUrlQuery(), 0, QVariantMap(),
				ODataRequestHandler::Method::GET);
		EXPECT_EQ(result.toJsonObject()["@context"].toString(),
				"https://localhost:8000/odata/$metadata");
		EXPECT_EQ(result.toJsonObject()["value"].toArray().count(), 2);
		EXPECT_EQ(
				result.toJsonObject()["value"].toArray()[1].toObject()["name"],
				"TestEntity2");
		EXPECT_EQ(
				result.toJsonObject()["value"].toArray()[1].toObject()["kind"],
				"EntitySet");
		EXPECT_EQ(
				result.toJsonObject()["value"].toArray()[1].toObject()["title"],
				"Test Entity 2");
		EXPECT_EQ(result.toJsonObject()["value"].toArray()[1].toObject()["url"],
				"Test2.TestEntity2Set");

		EXPECT_EQ(
				result.toJsonObject()["value"].toArray()[0].toObject()["name"],
				"TestEntity");
		EXPECT_EQ(
				result.toJsonObject()["value"].toArray()[0].toObject()["kind"],
				"EntitySet");
		EXPECT_EQ(
				result.toJsonObject()["value"].toArray()[0].toObject()["title"],
				"Test Entity");
		EXPECT_EQ(result.toJsonObject()["value"].toArray()[0].toObject()["url"],
				"Test.TestEntitySet");
	} catch (std::exception *ex) {
		std::cout << ex->what();
	}
}

TEST(ODataEntityPluginTest, returnDataForEntity) {

	try {
		ODataRequestHandler * handler = setupHandler();
		QVariant result = handler->handleRequest(
				QUrl("https://localhost:8000/odata/Test.TestEntitySet(Id=1)"),
				QUrlQuery(), 0, QVariantMap(), ODataRequestHandler::Method::GET);
		QJsonObject json = result.toJsonObject();
		QJsonDocument doc(json);
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		qDebug() << jsonString;
		EXPECT_EQ(json.value("Id").toInt(0), 1);
		EXPECT_EQ(json.value("Field").toString(""), "Test");
	}catch(std::exception * ex){
		qDebug() << ex->what();
	}
}
TEST(ODataEntityPluginTest, returnsDataOfReference) {

	try {
		ODataRequestHandler * handler = setupHandler();
		QVariant result = handler->handleRequest(
				QUrl("https://localhost:8000/odata/Test.TestEntitySet(Id=1)/TestEntity2"),
				QUrlQuery(), 0,QVariantMap(), ODataRequestHandler::Method::GET);
		QJsonObject json = result.toJsonObject();
		QJsonDocument doc(json);
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		qDebug() << jsonString;
		EXPECT_EQ(json.value("Id2").toInt(0), 1);
		EXPECT_EQ(json.value("Field2").toString(""), "asfasfwqer");
	}catch(std::exception * ex){
		qDebug() << ex->what();
	}
}


TEST(ODataEntityPluginTest, returnDataForEntitySet) {
	try {
		ODataRequestHandler * handler = setupHandler();
		QVariant result = handler->handleRequest(
				QUrl("https://localhost:8000/odata/Test.TestEntitySet"),
				QUrlQuery(), 0,QVariantMap(), ODataRequestHandler::Method::GET);
		QJsonObject json = result.toJsonObject();
		QJsonDocument doc(json);
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		qDebug() << jsonString;
		EXPECT_EQ(
				json.value("value").toArray().size(), 1);
		EXPECT_EQ(
				json.value("value").toArray().at(0).toObject().value("Id").toInt(
						0), 1);
		EXPECT_EQ(
				json.value("value").toArray().at(0).toObject().value("Field").toString(
						""), "Test");
		result = handler->handleRequest(
				QUrl("https://localhost:8000/odata/Test.TestEntitySet"),
				QUrlQuery(), 0,QVariantMap(), ODataRequestHandler::Method::GET);
		json = result.toJsonObject();
		doc = QJsonDocument(json);
		jsonString = doc.toJson(QJsonDocument::Indented);
		qDebug() << jsonString;
		EXPECT_EQ(
				json.value("value").toArray().size(), 1);
		EXPECT_EQ(
				json.value("value").toArray().at(0).toObject().value("Id").toInt(
						0), 1);
		EXPECT_EQ(
				json.value("value").toArray().at(0).toObject().value("Field").toString(
						""), "Test");

	} catch (std::exception *ex) {
		std::cout << ex->what();
	}
}

TEST(ODataEntityPluginTest, returnMetadata) {
	try {
		ODataRequestHandler * handler = setupHandler();
		QVariant result = handler->handleRequest(
				QUrl("https://localhost:8000/odata/$metadata"), QUrlQuery(), 0,QVariantMap(),
				ODataRequestHandler::Method::GET);

		QDomDocument *dom = new QDomDocument("metadata");

		qDebug() << result.toString();
		dom->setContent(result.toString());

		EXPECT_EQ(dom->childNodes().count(), 1);
		QDomElement root = dom->childNodes().at(0).toElement();
		EXPECT_EQ(root.tagName(), "edmx:Edmx");
		EXPECT_EQ(root.attributes().namedItem("xmlns:edmx").toAttr().value(),
				"http://docs.oasis-open.org/odata/ns/edmx");
		EXPECT_EQ(root.attributes().namedItem("Version").toAttr().value(),
				"4.0");
		EXPECT_EQ(root.childNodes().count(), 1);

		QDomElement dataServices = root.childNodes().at(0).toElement();
		EXPECT_EQ(dataServices.tagName(), "edmx:DataServices");
		EXPECT_EQ(dataServices.childNodes().count(), 2);

		QDomElement schema = dataServices.childNodes().at(0).toElement();
		EXPECT_EQ(schema.tagName(), "Schema");
		EXPECT_EQ(schema.attributes().namedItem("xmlns").toAttr().value(),
				"http://docs.oasis-open.org/odata/ns/edm");
		EXPECT_EQ(schema.attributes().namedItem("Namespace").toAttr().value(),
				"Test");

		QDomElement entity = schema.childNodes().at(0).toElement();
		EXPECT_EQ(entity.tagName().toStdString(), "EntityType");
		EXPECT_EQ(entity.attributes().namedItem("Name").toAttr().value().toStdString(),
				"TestEntity");
		QDomElement property = entity.childNodes().at(1).toElement();
		EXPECT_EQ(property.tagName().toStdString(), "Property");
		EXPECT_EQ(property.attributes().namedItem("Name").toAttr().value().toStdString(),
				"Id");
		EXPECT_EQ(property.attributes().namedItem("Type").toAttr().value().toStdString(),
				"Edm.Int32");
		property = entity.childNodes().at(0).toElement();
		EXPECT_EQ(property.tagName().toStdString(), "Property");
		EXPECT_EQ(property.attributes().namedItem("Name").toAttr().value().toStdString(),
				"Field");
		EXPECT_EQ(property.attributes().namedItem("Type").toAttr().value().toStdString(),
				"Edm.String");
		property = entity.childNodes().at(2).toElement();
		EXPECT_EQ(property.tagName().toStdString(), "NavigationProperty");
		EXPECT_EQ(property.attributes().namedItem("Name").toAttr().value().toStdString(),
				"TestEntity2");
		EXPECT_EQ(property.attributes().namedItem("Type").toAttr().value().toStdString(),
				"Test.TestEntity2");
		QDomElement keyProp = entity.childNodes().at(3).toElement();
		EXPECT_EQ(keyProp.tagName().toStdString(), "Key");
		EXPECT_EQ(keyProp.childNodes().at(0).toElement().tagName().toStdString(),
				"PropertyRef");
		EXPECT_EQ(
				keyProp.childNodes().at(0).toElement().attributes().namedItem(
						"Name").toAttr().value().toStdString(), "Id");
		QDomElement entityContainer = schema.childNodes().at(1).toElement();
		EXPECT_EQ(entityContainer.tagName().toStdString(), "EntityContainer");
		EXPECT_EQ(entityContainer.childNodes().count(), 1);
		QDomElement entitySet = entityContainer.childNodes().at(0).toElement();
		EXPECT_EQ(entitySet.tagName().toStdString(), "EntitySet");
		EXPECT_EQ(entitySet.attributes().namedItem("Name").toAttr().value().toStdString(),
				"TestEntitySet");
		EXPECT_EQ(
				entitySet.attributes().namedItem("EntityType").toAttr().value().toStdString(),
				"Test.TestEntity");

		schema = dataServices.childNodes().at(1).toElement();
		EXPECT_EQ(schema.tagName().toStdString(), "Schema");
		EXPECT_EQ(schema.attributes().namedItem("xmlns").toAttr().value().toStdString(),
				"http://docs.oasis-open.org/odata/ns/edm");
		EXPECT_EQ(schema.attributes().namedItem("Namespace").toAttr().value().toStdString(),
				"Test2");

		entity = schema.childNodes().at(0).toElement();
		EXPECT_EQ(entity.tagName().toStdString(), "EntityType");
		EXPECT_EQ(entity.attributes().namedItem("Name").toAttr().value().toStdString(),
				"TestEntity2");
		property = entity.childNodes().at(1).toElement();
		EXPECT_EQ(property.tagName().toStdString(), "Property");
		EXPECT_EQ(property.attributes().namedItem("Name").toAttr().value().toStdString(),
				"Id2");
		EXPECT_EQ(property.attributes().namedItem("Type").toAttr().value().toStdString(),
				"Edm.Int32");
		property = entity.childNodes().at(0).toElement();
		EXPECT_EQ(property.tagName().toStdString(), "Property");
		EXPECT_EQ(property.attributes().namedItem("Name").toAttr().value().toStdString(),
				"Field2");
		EXPECT_EQ(property.attributes().namedItem("Type").toAttr().value().toStdString(),
				"Edm.Guid");
		keyProp = entity.childNodes().at(2).toElement();
		EXPECT_EQ(keyProp.tagName().toStdString(), "Key");
		EXPECT_EQ(keyProp.childNodes().at(0).toElement().tagName().toStdString(),
				"PropertyRef");
		EXPECT_EQ(
				keyProp.childNodes().at(0).toElement().attributes().namedItem(
						"Name").toAttr().value().toStdString(), "Id2");
		entityContainer = schema.childNodes().at(1).toElement();
		EXPECT_EQ(entityContainer.tagName().toStdString(), "EntityContainer");
		EXPECT_EQ(entityContainer.childNodes().count(), 1);
		entitySet = entityContainer.childNodes().at(0).toElement();
		EXPECT_EQ(entitySet.tagName().toStdString(), "EntitySet");
		EXPECT_EQ(entitySet.attributes().namedItem("Name").toAttr().value().toStdString(),
				"TestEntity2Set");
		EXPECT_EQ(
				entitySet.attributes().namedItem("EntityType").toAttr().value().toStdString(),
				"Test2.TestEntity2");
	} catch (std::exception *ex) {
		std::cout << ex->what();
	}
}
