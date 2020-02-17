#ifndef ODataURLWalk_H
#define ODataURLWalk_H

#include <QObject>
#include <ODataServer_global.h>
#include <model/ODataModel.h>
#include <QUrlQuery>

class ODATASERVER_EXPORT ODataURLWalk : public QObject
{
    Q_OBJECT

public:
    explicit ODataURLWalk(ODataModel* model, QUrl url, QUrlQuery query, QVariant body, QObject *parent = nullptr);

private:
    ODataModel* model;
    int currentPathIndex = 0;
    QVariant currentResult;
public:
    QVariant walkURL(QStringList segments);

};

#endif // ODataURLWalk_H
