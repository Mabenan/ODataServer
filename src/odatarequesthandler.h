#ifndef ODATAURLHANDLER_H
#define ODATAURLHANDLER_H

#include <QObject>
#include "ODataServer_global.h"
#include <QUrl>
#include <QUrlQuery>
#include <QVariant>
#include "ODataModel.h"
#include "ODataURLParser.h"

class ODATASERVER_EXPORT ODataRequestHandler : public QObject
{
    Q_OBJECT
private:
    ODataURLParser * urlParser;
    ODataModel * model;
    QString host;
    QString base;
public:
    explicit ODataRequestHandler(QString host, QString base,QObject *parent = nullptr);

    QVariant handleRequest(QUrl url, QUrlQuery query);

signals:

public slots:
};

#endif // ODATAURLHANDLER_H
