#ifndef ODATATESTCONTROLLER2_H
#define ODATATESTCONTROLLER2_H

#include <odataentitycontroller.h>
class ODataTestController2 : public ODataEntityController
{
public:
    ODataTestController2();

    // ODataEntityController interface
public:
    void get(QMap<QString, QVariant> keys, QUrlQuery query) const;
    void getSet(QMap<QString, ODataFilter> filter, QUrlQuery query) const;
    void updateSet(QList<ODataEntity> changedEntities) const;
    void deleteSet(QList<ODataEntity> changedEntities) const;
    void insertSet(QList<ODataEntity> changedEntities) const;
    ODataEntitySet * getEntitySet();
};

#endif // ODATATESTCONTROLLER2_H
