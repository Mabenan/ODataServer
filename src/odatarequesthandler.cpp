#include "odatarequesthandler.h"
#include "ODataServiceDocument.h"
#include "odataentitycontroller.h"
ODataRequestHandler::ODataRequestHandler(QObject *parent) : QObject(parent)
{
    this->urlParser = new ODataURLParser(this);
    this->model = new ODataModel(this);
}

QVariant ODataRequestHandler::handleRequest(QString base, QUrl url, QUrlQuery query)
{
    if (url.path() == base)
    {
        ODataServiceDocument * serviceDoc = new ODataServiceDocument(this);
        serviceDoc->context = url.adjusted(QUrl::RemovePath |
                                           QUrl::RemoveQuery |
                                           QUrl::RemoveFragment ).toString() + base + "$metadata";
        QMap<QString, ODataEntityController *> map = this->model->getEntities();
        foreach(QString key, map.keys()){
            ODataServiceDocumentEntry * docEntry = new ODataServiceDocumentEntry();
            docEntry->name = map[key]->getName();
            docEntry->url = map[key]->getName() + "Set";
            docEntry->kind = "EntitySet";
            docEntry->title = map[key]->getDescription();
            serviceDoc->value.push_back(docEntry);
        }
        return serviceDoc->getJson();
    }else if(url.path().toLower() == base + "$metadata"){
        return "";
    }
    else
    {
        this->urlParser->splitUpURL(url);
        return "";
    }
}
