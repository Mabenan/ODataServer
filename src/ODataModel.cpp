#include "ODataModel.h"
#include "ODataEntityInterface.h"
#include "odataentitycontroller.h"
#include <QPluginLoader>
#include <QCoreApplication>
#include <QDir>
#include "ODataEntitySet.h"
ODataModel::ODataModel(QString host, QString base, QObject *parent) :
		QObject(parent) {
	this->host = host;
	this->base = base;
}

QMap<QString, ODataEntitySet *> ODataModel::getEntitySets() {
	if (this->entitySets.count() == 0) {
		QDir pluginsDir = QDir(QCoreApplication::applicationDirPath());
		QStringList entryList = pluginsDir.entryList(QDir::Files);
		pluginsDir.cd("plugins");
		entryList.append(pluginsDir.entryList(QDir::Files));
		for (QString &fileName : entryList) {
			QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
			QObject *plugin = loader.instance();
			auto entityInterface = qobject_cast<ODataEntityInterface *>(plugin);
			if (entityInterface) {
				QList<ODataEntityController *> controllers =
						entityInterface->GetEntityControllers();
				foreach (ODataEntityController * controller, controllers)
				{

					this->entitySets.insert(controller->getEntitySet()->getName(), controller->getEntitySet());
				}
			}
		}
	}

	return this->entitySets;
}

ODataServiceDocument* ODataModel::getServiceDocument() {
	ODataServiceDocument * serviceDoc = new ODataServiceDocument(this);
	serviceDoc->context = this->host + this->base + "$metadata";
	QMap<QString, ODataEntitySet *> map = this->getEntitySets();
	foreach(QString key, map.keys())
	{
		ODataServiceDocumentEntry * docEntry = new ODataServiceDocumentEntry();
		docEntry->name = map[key]->getEntity()->getName();
		docEntry->url = map[key]->getName();
		docEntry->kind = "EntitySet";
		docEntry->title = map[key]->getEntity()->getDescription();
		serviceDoc->value.push_back(docEntry);
	}
	return serviceDoc;
}
