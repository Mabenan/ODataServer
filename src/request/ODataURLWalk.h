#ifndef ODataURLWalk_H
#define ODataURLWalk_H

#include <QObject>
#include <ODataServer_global.h>
#include <model/ODataModel.h>
#include <QUrlQuery>
#include <request/odatarequesthandler.h>
class ODATASERVER_EXPORT ODataURLWalk : public QObject
{
    Q_OBJECT

public:
    explicit ODataURLWalk(ODataModel* model, QUrl url, QUrlQuery query, QVariant body, ODataRequestHandler::Method method, QObject *parent = nullptr);

private:
    ODataModel* model;
    QUrl url;
    QUrlQuery query;
    QVariant body;
    ODataRequestHandler::Method method;
    int currentPathIndex = 0;
    QVariant currentResult;
    ODataEntity * lastEntity;
public:
    QVariant walkURL(QStringList segments);

};

#endif // ODataURLWalk_H
