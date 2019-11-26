#include <tst_odataentityplugin.h>
// add necessary includes here



ODataEntityPluginTest::ODataEntityPluginTest() {
	this->a = nullptr;
	this->handler = nullptr;
}

ODataEntityPluginTest::~ODataEntityPluginTest() {
}

void ODataEntityPluginTest::addsAllEntitiesOfPlugins() {
	ODataModel *model = new ODataModel("https://localhost:8000/", "/odata/");
	auto entities = model->getEntitySets();

	QCOMPARE(entities.count(), 2);
	QVERIFY(entities.contains("Test.TestEntitySet"));
	QVERIFY(entities["Test.TestEntitySet"]->getName() == "TestEntitySet");

}

void ODataEntityPluginTest::returnServiceDocumentforAllEntities() {
	QVariant result = handler->handleRequest(
			QUrl("https://localhost:8000/odata/"), QUrlQuery());
	QCOMPARE(result.toJsonObject()["@context"].toString(),
			"https://localhost:8000/odata/$metadata");
	QCOMPARE(result.toJsonObject()["value"].toArray().count(), 2);
	QCOMPARE(result.toJsonObject()["value"].toArray()[1].toObject()["name"],
			"TestEntity2");
	QCOMPARE(result.toJsonObject()["value"].toArray()[1].toObject()["kind"],
			"EntitySet");
	QCOMPARE(result.toJsonObject()["value"].toArray()[1].toObject()["title"],
			"Test Entity 2");
	QCOMPARE(result.toJsonObject()["value"].toArray()[1].toObject()["url"],
			"Test2.TestEntity2Set");

	QCOMPARE(result.toJsonObject()["value"].toArray()[0].toObject()["name"],
			"TestEntity");
	QCOMPARE(result.toJsonObject()["value"].toArray()[0].toObject()["kind"],
			"EntitySet");
	QCOMPARE(result.toJsonObject()["value"].toArray()[0].toObject()["title"],
			"Test Entity");
	QCOMPARE(result.toJsonObject()["value"].toArray()[0].toObject()["url"],
			"Test.TestEntitySet");
}

void ODataEntityPluginTest::returnMetadata() {
	QVariant result = handler->handleRequest(
			QUrl("https://localhost:8000/odata/$metadata"), QUrlQuery());

	QDomDocument *dom = new QDomDocument("metadata");

	qDebug() << result.toString();
	dom->setContent(result.toString());

	QCOMPARE(dom->childNodes().count(), 1);
	QDomElement root = dom->childNodes().at(0).toElement();
	QCOMPARE(root.tagName(), "edmx:Edmx");
	QCOMPARE(root.attributes().namedItem("xmlns:edmx").toAttr().value(), "http://docs.oasis-open.org/odata/ns/edmx");
	QCOMPARE(root.attributes().namedItem("Version").toAttr().value(), "4.0");
	QCOMPARE(root.childNodes().count(), 1);

	QDomElement dataServices = root.childNodes().at(0).toElement();
	QCOMPARE(dataServices.tagName(), "edmx:DataServices");
	QCOMPARE(dataServices.childNodes().count(), 2);

	QDomElement schema = dataServices.childNodes().at(0).toElement();
	QCOMPARE(schema.tagName(), "Schema");
	QCOMPARE(schema.attributes().namedItem("xmlns").toAttr().value(), "http://docs.oasis-open.org/odata/ns/edm");
	QCOMPARE(schema.attributes().namedItem("Namespace").toAttr().value(), "Test");

	QDomElement entity = schema.childNodes().at(0).toElement();
	QCOMPARE(entity.tagName(), "EntityType");
	QCOMPARE(entity.attributes().namedItem("Name").toAttr().value(), "TestEntity");
	QDomElement property = entity.childNodes().at(1).toElement();
	QCOMPARE(property.tagName(), "Property");
	QCOMPARE(property.attributes().namedItem("Name").toAttr().value(), "Id");
	QCOMPARE(property.attributes().namedItem("Type").toAttr().value(), "Edm.Int32");
    property = entity.childNodes().at(0).toElement();
	QCOMPARE(property.tagName(), "Property");
	QCOMPARE(property.attributes().namedItem("Name").toAttr().value(), "Field");
	QCOMPARE(property.attributes().namedItem("Type").toAttr().value(), "Edm.String");
    QDomElement keyProp = entity.childNodes().at(2).toElement();
    QCOMPARE(keyProp.tagName(), "Key");
    QCOMPARE(keyProp.childNodes().at(0).toElement().tagName(), "PropertyRef");
    QCOMPARE(keyProp.childNodes().at(0).toElement().attributes().namedItem("Name").toAttr().value(), "Id");
	QDomElement entityContainer = schema.childNodes().at(1).toElement();
	QCOMPARE(entityContainer.tagName(), "EntityContainer");
	QCOMPARE(entityContainer.childNodes().count(), 1);
	QDomElement entitySet = entityContainer.childNodes().at(0).toElement();
	QCOMPARE(entitySet.tagName(), "EntitySet");
	QCOMPARE(entitySet.attributes().namedItem("Name").toAttr().value(), "TestEntitySet");
	QCOMPARE(entitySet.attributes().namedItem("EntityType").toAttr().value(), "Test.TestEntity");

	schema = dataServices.childNodes().at(1).toElement();
	QCOMPARE(schema.tagName(), "Schema");
	QCOMPARE(schema.attributes().namedItem("xmlns").toAttr().value(), "http://docs.oasis-open.org/odata/ns/edm");
	QCOMPARE(schema.attributes().namedItem("Namespace").toAttr().value(), "Test2");

	entity = schema.childNodes().at(0).toElement();
	QCOMPARE(entity.tagName(), "EntityType");
	QCOMPARE(entity.attributes().namedItem("Name").toAttr().value(), "TestEntity2");
	property = entity.childNodes().at(1).toElement();
	QCOMPARE(property.tagName(), "Property");
	QCOMPARE(property.attributes().namedItem("Name").toAttr().value(), "Id2");
	QCOMPARE(property.attributes().namedItem("Type").toAttr().value(), "Edm.Int32");
    property = entity.childNodes().at(0).toElement();
	QCOMPARE(property.tagName(), "Property");
	QCOMPARE(property.attributes().namedItem("Name").toAttr().value(), "Field2");
	QCOMPARE(property.attributes().namedItem("Type").toAttr().value(), "Edm.Guid");
    keyProp = entity.childNodes().at(2).toElement();
    QCOMPARE(keyProp.tagName(), "Key");
    QCOMPARE(keyProp.childNodes().at(0).toElement().tagName(), "PropertyRef");
    QCOMPARE(keyProp.childNodes().at(0).toElement().attributes().namedItem("Name").toAttr().value(), "Id2");
	entityContainer = schema.childNodes().at(1).toElement();
	QCOMPARE(entityContainer.tagName(), "EntityContainer");
	QCOMPARE(entityContainer.childNodes().count(), 1);
	entitySet = entityContainer.childNodes().at(0).toElement();
	QCOMPARE(entitySet.tagName(), "EntitySet");
	QCOMPARE(entitySet.attributes().namedItem("Name").toAttr().value(), "TestEntity2Set");
	QCOMPARE(entitySet.attributes().namedItem("EntityType").toAttr().value(), "Test2.TestEntity2");

}

#include "tst_odataentityplugin.moc"
