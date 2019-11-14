#ifndef ODATAENTITYCONTROLLER_H
#define ODATAENTITYCONTROLLER_H

#include "ODataServer_global.h"
#include <QObject>
#include <QUrlQuery>
#include "ODataModel.h"
#include "ODataFilter.h"
#include "ODataEntitySet.h"

class ODATASERVER_EXPORT ODataEntityController : public QObject
{
    Q_OBJECT
public:
    explicit ODataEntityController(QObject *parent = nullptr);


    virtual void get(QMap<QString, QVariant> keys, QUrlQuery query) const = 0;
    virtual void getSet(QMap<QString, ODataFilter> filter, QUrlQuery query) const = 0;
    virtual void updateSet(QList<ODataEntity> changedEntities) const = 0;
    virtual void deleteSet(QList<ODataEntity> changedEntities) const = 0;
    virtual void insertSet(QList<ODataEntity> changedEntities) const = 0;
    virtual ODataEntitySet * getEntitySet() = 0;
signals:

public slots:
};

#endif // ODATAENTITYCONTROLLER_H
