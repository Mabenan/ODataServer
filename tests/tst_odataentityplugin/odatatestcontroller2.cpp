#include "odatatestcontroller2.h"
#include "ODataTestEntity2.h"

ODataTestController2::ODataTestController2()
{

}

void ODataTestController2::get(QMap<QString, QVariant> keys, QUrlQuery query) const
{

}

void ODataTestController2::getSet(QMap<QString, ODataFilter> filter, QUrlQuery query) const
{

}

void ODataTestController2::updateSet(QList<ODataEntity> changedEntities) const
{

}

void ODataTestController2::deleteSet(QList<ODataEntity> changedEntities) const
{

}

void ODataTestController2::insertSet(QList<ODataEntity> changedEntities) const
{

}

QString ODataTestController2::getName() const
{
    return "TestEntity2";
}

ODataEntity *ODataTestController2::getNewEntity() const
{
    return new ODataTestEntity2();

}

QString ODataTestController2::getDescription() const
{
    return "Test Entity 2";
}
