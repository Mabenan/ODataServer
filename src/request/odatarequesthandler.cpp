#include <odatarequesthandler.h>
#include <ODataServiceDocument.h>
#include <response/ODataMetadata.h>
#include <QVariant>
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
        ODataMetadata * metadata = this->model->getMetadata();
        return QVariant(metadata->getAsXML()->toString());
    }
    else
    {
        this->urlParser->splitUpURL(url);
        return "";
    }
}
