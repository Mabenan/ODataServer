#include "odatarequesthandler.h"
#include "ODataServiceDocument.h"
#include "odataentitycontroller.h"
ODataRequestHandler::ODataRequestHandler(QString host, QString base,QObject *parent) : QObject(parent)
{
    this->urlParser = new ODataURLParser(this);
    this->host = host;
    this->base = base;
    this->model = new ODataModel(host,base,this);
}

QVariant ODataRequestHandler::handleRequest(QUrl url, QUrlQuery query)
{
    if (url.path() == this->base)
    {
    	ODataServiceDocument * serviceDoc = this->model->getServiceDocument();
        return serviceDoc->getJson();
    }else if(url.path().toLower() == this->base + "$metadata"){
        return "";
    }
    else
    {
        this->urlParser->splitUpURL(url);
        return "";
    }
}
