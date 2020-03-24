#include <model/ODataEntitySet.h>
#include <model/ODataModel.h>
#include <QPluginLoader>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>
ODataModel::ODataModel(QString host, QString base, QMap<QString, ODataSchema *> schemas, QObject *parent) :
		QObject(parent) {
	this->host = host;
	this->base = base;
	this->schemas = schemas;
}

QMap<QString, ODataEntitySet *> ODataModel::getEntitySets() {
	QMap<QString, ODataEntitySet * > entitySets;
	for(QString key : this->schemas.keys()){
		QString entityPrefix = this->schemas[key]->getNamespace() + ".";
		for(QString key2 : this->schemas[key]->getEntityContainer()->entitySets.keys()){
			entitySets.insert(key2,this->schemas[key]->getEntityContainer()->entitySets[key2]);
		}
	}
	return entitySets;
}

ODataServiceDocument* ODataModel::getServiceDocument() {
	ODataServiceDocument * serviceDoc = new ODataServiceDocument(this);
	serviceDoc->context = this->host + this->base + "$metadata";
	QMap<QString, ODataEntitySet *> map = this->getEntitySets();
	for(QString key : map.keys())
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
	return new ODataMetadata(this->schemas);
}

QMap<QString, ODataAction * > ODataModel::getActions(){
	QMap<QString, ODataAction * > actions;
	for(QString key : this->schemas.keys()){
		QString entityPrefix = this->schemas[key]->getNamespace() + ".";
		for(QString key2 : this->schemas[key]->getEntityContainer()->actionImports.keys()){
			actions.insert(key2,this->schemas[key]->getEntityContainer()->actionImports[key2]);
		}
	}
	return actions;

}

QMap<QString, ODataFunction * > ODataModel::getFunctions(){
	QMap<QString, ODataFunction * > functions;
	for(QString key : this->schemas.keys()){
		QString entityPrefix = this->schemas[key]->getNamespace() + ".";
		for(QString key2 : this->schemas[key]->getEntityContainer()->functions.keys()){
			functions.insert(key2,this->schemas[key]->getEntityContainer()->functions[key2]);
		}
	}
	return functions;

}
