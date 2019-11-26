#ifndef ODATA_ENTITY_PLUGIN_TEST_H
#define ODATA_ENTITY_PLUGIN_TEST_H
#include <QtTest>
#include <QList>
#include <QString>
#include <request/ODataURLParser.h>
#include <model/ODataModel.h>
#include <interface/ODataEntityInterface.h>
#include <request/odatarequesthandler.h>
#include <QtXml>

class ODataEntityPluginTest: public QObject {
Q_OBJECT

private:
	QCoreApplication *a;
	ODataRequestHandler *handler;
public:
	ODataEntityPluginTest();
	~ODataEntityPluginTest();

public:
private slots:
	void initTestCase() {
		char *args;
		int argc = 0;
		this->a = new QCoreApplication(argc, &args);
		this->handler = new ODataRequestHandler("https://localhost:8000",
				"/odata/");
		qDebug() << this->a->applicationDirPath();
	}
	void addsAllEntitiesOfPlugins();
	void returnServiceDocumentforAllEntities();
	void returnMetadata();

	void cleanupTestCase() {
	}
};
#endif
