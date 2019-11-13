#include <QtTest>
#include <QList>
#include <QString>
#include <ODataURLParser.h>
#include <ODataModel.h>
#include <ODataEntityInterface.h>
#include <odatarequesthandler.h>
// add necessary includes here

class ODataEntityPluginTest : public QObject
{
    Q_OBJECT

private:
    QCoreApplication * a;
public:
    ODataEntityPluginTest();
    ~ODataEntityPluginTest();

public:
private slots:
    void initTestCase()
    {
        char *args;
        int argc = 0;
        this->a = new QCoreApplication(argc, &args);
    }
    void addsAllEntitiesOfPlugins();
    void returnServiceDocumentforAllEntities();

    void cleanupTestCase()
    {
    }
};

ODataEntityPluginTest::ODataEntityPluginTest()
{
}

ODataEntityPluginTest::~ODataEntityPluginTest()
{
}

void ODataEntityPluginTest::addsAllEntitiesOfPlugins()
{
    ODataModel * model = new ODataModel();
    auto entities = model->getEntities();

    QVERIFY(entities.contains("TestEntity"));
    QVERIFY(entities["TestEntity"]->getName() == "TestEntity");

}

void ODataEntityPluginTest::returnServiceDocumentforAllEntities()
{
    ODataRequestHandler * handler = new ODataRequestHandler();
    QVariant result = handler->handleRequest("/odata/", QUrl("https://localhost:8000/odata/"), QUrlQuery());
    QCOMPARE(result.toJsonObject()["@context"].toString(), "https://localhost:8000/odata/$metadata");
    QCOMPARE(result.toJsonObject()["value"].toArray()[0].toObject()["name"], "TestEntity");
    QCOMPARE(result.toJsonObject()["value"].toArray()[0].toObject()["kind"], "EntitySet");
    QCOMPARE(result.toJsonObject()["value"].toArray()[0].toObject()["title"], "Test Entity");
    QCOMPARE(result.toJsonObject()["value"].toArray()[0].toObject()["url"], "TestEntitySet");

    QCOMPARE(result.toJsonObject()["value"].toArray()[1].toObject()["name"], "TestEntity2");
    QCOMPARE(result.toJsonObject()["value"].toArray()[1].toObject()["kind"], "EntitySet");
    QCOMPARE(result.toJsonObject()["value"].toArray()[1].toObject()["title"], "Test Entity 2");
    QCOMPARE(result.toJsonObject()["value"].toArray()[1].toObject()["url"], "TestEntity2Set");
}

QTEST_APPLESS_MAIN(ODataEntityPluginTest)

#include "tst_odataentityplugin.moc"
