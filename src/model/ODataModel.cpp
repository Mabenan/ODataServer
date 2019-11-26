#include <interface/ODataEntityInterface.h>
#include <model/ODataEntitySet.h>
#include <model/ODataModel.h>
#include <QPluginLoader>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>
ODataModel::ODataModel(QString host, QString base, QObject *parent) :
		QObject(parent) {
	this->host = host;
	this->base = base;
}

void ODataModel::ensureSchemas() {
	if (this->schemas.count() == 0) {
		QDir pluginsDir = QDir(QCoreApplication::applicationDirPath());
		QStringList entryList = pluginsDir.entryList(QDir::Files);
		pluginsDir.cd("plugins");
		entryList.append(pluginsDir.entryList(QDir::Files));
		for (QString& fileName : entryList) {
			qDebug() << fileName;
			QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
			QObject* plugin = loader.instance();
			auto entityInterface = qobject_cast<ODataEntityInterface*>(plugin);
			if (entityInterface) {
				QList<ODataSchema *> schemas =
						entityInterface->GetSchemas();
				foreach (ODataSchema * schema, schemas)
				{

					this->schemas.insert( schema->getNamespace(),
							schema);
				}
			} else {
				qDebug() << loader.errorString();
			}
		}
	}
}

QMap<QString, ODataEntitySet *> ODataModel::getEntitySets() {
	this->ensureSchemas();
	QMap<QString, ODataEntitySet * > entitySets;
	foreach(QString key, this->schemas.keys()){
		QString entityPrefix = this->schemas[key]->getNamespace() + ".";
		foreach(QString key2, this->schemas[key]->getEntityContainer()->entitySets.keys()){
			entitySets.insert(entityPrefix + key2,this->schemas[key]->getEntityContainer()->entitySets[key2]);
		}
	}
	return entitySets;
}

ODataServiceDocument* ODataModel::getServiceDocument() {
	ODataServiceDocument * serviceDoc = new ODataServiceDocument(this);
	serviceDoc->context = this->host + this->base + "$metadata";
	QMap<QString, ODataEntitySet *> map = this->getEntitySets();
	foreach(QString key, map.keys())
	{
		ODataServiceDocumentEntry * docEntry = new ODataServiceDocumentEntry();
		docEntry->name = map[key]->getDefaultEntity()->getName();
		docEntry->url = key;
		docEntry->kind = "EntitySet";
		docEntry->title = map[key]->getDefaultEntity()->getDescription();
		serviceDoc->value.push_back(docEntry);
	}
	return serviceDoc;
}

ODataMetadata* ODataModel::getMetadata() {
	this->ensureSchemas();
	return new ODataMetadata(this->schemas);
}
