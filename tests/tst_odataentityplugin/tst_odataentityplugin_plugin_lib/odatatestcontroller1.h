#ifndef ODATATESTCONTROLLER1_H
#define ODATATESTCONTROLLER1_H

#include <interface/odataentitycontroller.h>
class ODataTestController1 : public ODataEntityController
{
public:
    ODataTestController1();

    // ODataEntityController interface
public:
    void get(QMap<QString, QVariant> keys, QUrlQuery query) const;
    void getSet(QMap<QString, ODataFilter> filter, QUrlQuery query) const;
    void updateSet(QList<ODataEntity> changedEntities) const;
    void deleteSet(QList<ODataEntity> changedEntities) const;
    void insertSet(QList<ODataEntity> changedEntities) const;
    ODataEntitySet * getEntitySet();

};

#endif // ODATATESTCONTROLLER1_H
