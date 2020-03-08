#include <odatarequesthandler.h>
#include <ODataServiceDocument.h>
#include <response/ODataMetadata.h>
#include <QVariant>
#include <ODataURLWalk.h>

ODataRequestHandler::ODataRequestHandler(QString host, QString base, QMap<QString, ODataSchema *> schemas,QObject *parent) : QObject(parent)
{
    this->urlParser = new ODataURLParser(this);
    this->host = host;
    this->base = base;
    this->model = new ODataModel(host,base, schemas,this);
}

QVariant ODataRequestHandler::handleRequest(QUrl url, QUrlQuery query, QVariant body, Method method)
{
    if (url.path() == this->base)
    {
    	ODataServiceDocument * serviceDoc = this->model->getServiceDocument();
        return serviceDoc->getJson();
    }else if(url.path().toLower() == this->base + "$metadata"){
        ODataMetadata * metadata = this->model->getMetadata();
        return QVariant(metadata->getAsXML()->toString());
    }
    else
    {
        QStringList urlSegments = this->urlParser->splitUpURL(url);
        ODataURLWalk * urlWalk = new ODataURLWalk(this->model, url, query, body, method,this);
        QVariant result = urlWalk->walkURL(urlSegments);
        return result;
    }
}
