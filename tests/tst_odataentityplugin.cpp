
#include <gtest/gtest.h>
#include <QList>
#include <QString>
#include <request/ODataURLParser.h>
#include <model/ODataModel.h>
#include <interface/ODataEntityInterface.h>
#include <request/odatarequesthandler.h>
#include <QtXml>

TEST(ODataEntityPluginTest, addsAllEntitiesOfPlugins)
{
	try
	{
		char *args;
		int argc = 0;
		QCoreApplication *a = new QCoreApplication(argc, &args);
		ODataModel *model = new ODataModel("https://localhost:8000/", "/odata/");
		auto entities = model->getEntitySets();

		EXPECT_EQ(entities.count(), 2);
		EXPECT_TRUE(entities.contains("Test.TestEntitySet"));
		EXPECT_TRUE(entities["Test.TestEntitySet"]->getName() == "TestEntitySet");
	}
	catch (std::exception * ex)
	{
		std::cout << ex->what();
	}
}

TEST(ODataEntityPluginTest, returnServiceDocumentforAllEntities)
{
	try
	{
		char *args;
		int argc = 0;
		QCoreApplication *a = new QCoreApplication(argc, &args);
		ODataRequestHandler *handler = new ODataRequestHandler("https://localhost:8000", "/odata/");
		QVariant result = handler->handleRequest(
			QUrl("https://localhost:8000/odata/"), QUrlQuery(), 0, ODataRequestHandler::Method::GET);
		EXPECT_EQ(result.toJsonObject()["@context"].toString(),
				  "https://localhost:8000/odata/$metadata");
		EXPECT_EQ(result.toJsonObject()["value"].toArray().count(), 2);
		EXPECT_EQ(result.toJsonObject()["value"].toArray()[1].toObject()["name"],
				  "TestEntity2");
		EXPECT_EQ(result.toJsonObject()["value"].toArray()[1].toObject()["kind"],
				  "EntitySet");
		EXPECT_EQ(result.toJsonObject()["value"].toArray()[1].toObject()["title"],
				  "Test Entity 2");
		EXPECT_EQ(result.toJsonObject()["value"].toArray()[1].toObject()["url"],
				  "Test2.TestEntity2Set");

		EXPECT_EQ(result.toJsonObject()["value"].toArray()[0].toObject()["name"],
				  "TestEntity");
		EXPECT_EQ(result.toJsonObject()["value"].toArray()[0].toObject()["kind"],
				  "EntitySet");
		EXPECT_EQ(result.toJsonObject()["value"].toArray()[0].toObject()["title"],
				  "Test Entity");
		EXPECT_EQ(result.toJsonObject()["value"].toArray()[0].toObject()["url"],
				  "Test.TestEntitySet");
	}
	catch (std::exception * ex)
	{
		std::cout << ex->what();
	}
}

TEST(ODataEntityPluginTest, returnMetadata)
{
	try
	{
		char *args;
		int argc = 0;
		QCoreApplication *a = new QCoreApplication(argc, &args);
		ODataRequestHandler *handler = new ODataRequestHandler("https://localhost:8000", "/odata/");
		QVariant result = handler->handleRequest(
			QUrl("https://localhost:8000/odata/$metadata"), QUrlQuery(), 0, ODataRequestHandler::Method::GET);

		QDomDocument *dom = new QDomDocument("metadata");

		qDebug() << result.toString();
		dom->setContent(result.toString());

		EXPECT_EQ(dom->childNodes().count(), 1);
		QDomElement root = dom->childNodes().at(0).toElement();
		EXPECT_EQ(root.tagName(), "edmx:Edmx");
		EXPECT_EQ(root.attributes().namedItem("xmlns:edmx").toAttr().value(), "http://docs.oasis-open.org/odata/ns/edmx");
		EXPECT_EQ(root.attributes().namedItem("Version").toAttr().value(), "4.0");
		EXPECT_EQ(root.childNodes().count(), 1);

		QDomElement dataServices = root.childNodes().at(0).toElement();
		EXPECT_EQ(dataServices.tagName(), "edmx:DataServices");
		EXPECT_EQ(dataServices.childNodes().count(), 2);

		QDomElement schema = dataServices.childNodes().at(0).toElement();
		EXPECT_EQ(schema.tagName(), "Schema");
		EXPECT_EQ(schema.attributes().namedItem("xmlns").toAttr().value(), "http://docs.oasis-open.org/odata/ns/edm");
		EXPECT_EQ(schema.attributes().namedItem("Namespace").toAttr().value(), "Test");

		QDomElement entity = schema.childNodes().at(0).toElement();
		EXPECT_EQ(entity.tagName(), "EntityType");
		EXPECT_EQ(entity.attributes().namedItem("Name").toAttr().value(), "TestEntity");
		QDomElement property = entity.childNodes().at(1).toElement();
		EXPECT_EQ(property.tagName(), "Property");
		EXPECT_EQ(property.attributes().namedItem("Name").toAttr().value(), "Id");
		EXPECT_EQ(property.attributes().namedItem("Type").toAttr().value(), "Edm.Int32");
		property = entity.childNodes().at(0).toElement();
		EXPECT_EQ(property.tagName(), "Property");
		EXPECT_EQ(property.attributes().namedItem("Name").toAttr().value(), "Field");
		EXPECT_EQ(property.attributes().namedItem("Type").toAttr().value(), "Edm.String");
		QDomElement keyProp = entity.childNodes().at(2).toElement();
		EXPECT_EQ(keyProp.tagName(), "Key");
		EXPECT_EQ(keyProp.childNodes().at(0).toElement().tagName(), "PropertyRef");
		EXPECT_EQ(keyProp.childNodes().at(0).toElement().attributes().namedItem("Name").toAttr().value(), "Id");
		QDomElement entityContainer = schema.childNodes().at(1).toElement();
		EXPECT_EQ(entityContainer.tagName(), "EntityContainer");
		EXPECT_EQ(entityContainer.childNodes().count(), 1);
		QDomElement entitySet = entityContainer.childNodes().at(0).toElement();
		EXPECT_EQ(entitySet.tagName(), "EntitySet");
		EXPECT_EQ(entitySet.attributes().namedItem("Name").toAttr().value(), "TestEntitySet");
		EXPECT_EQ(entitySet.attributes().namedItem("EntityType").toAttr().value(), "Test.TestEntity");

		schema = dataServices.childNodes().at(1).toElement();
		EXPECT_EQ(schema.tagName(), "Schema");
		EXPECT_EQ(schema.attributes().namedItem("xmlns").toAttr().value(), "http://docs.oasis-open.org/odata/ns/edm");
		EXPECT_EQ(schema.attributes().namedItem("Namespace").toAttr().value(), "Test2");

		entity = schema.childNodes().at(0).toElement();
		EXPECT_EQ(entity.tagName(), "EntityType");
		EXPECT_EQ(entity.attributes().namedItem("Name").toAttr().value(), "TestEntity2");
		property = entity.childNodes().at(1).toElement();
		EXPECT_EQ(property.tagName(), "Property");
		EXPECT_EQ(property.attributes().namedItem("Name").toAttr().value(), "Id2");
		EXPECT_EQ(property.attributes().namedItem("Type").toAttr().value(), "Edm.Int32");
		property = entity.childNodes().at(0).toElement();
		EXPECT_EQ(property.tagName(), "Property");
		EXPECT_EQ(property.attributes().namedItem("Name").toAttr().value(), "Field2");
		EXPECT_EQ(property.attributes().namedItem("Type").toAttr().value(), "Edm.Guid");
		keyProp = entity.childNodes().at(2).toElement();
		EXPECT_EQ(keyProp.tagName(), "Key");
		EXPECT_EQ(keyProp.childNodes().at(0).toElement().tagName(), "PropertyRef");
		EXPECT_EQ(keyProp.childNodes().at(0).toElement().attributes().namedItem("Name").toAttr().value(), "Id2");
		entityContainer = schema.childNodes().at(1).toElement();
		EXPECT_EQ(entityContainer.tagName(), "EntityContainer");
		EXPECT_EQ(entityContainer.childNodes().count(), 1);
		entitySet = entityContainer.childNodes().at(0).toElement();
		EXPECT_EQ(entitySet.tagName(), "EntitySet");
		EXPECT_EQ(entitySet.attributes().namedItem("Name").toAttr().value(), "TestEntity2Set");
		EXPECT_EQ(entitySet.attributes().namedItem("EntityType").toAttr().value(), "Test2.TestEntity2");
	}
	catch (std::exception * ex)
	{
		std::cout << ex->what();
	}
}
