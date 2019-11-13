#include "odatatestcontroller1.h"
#include "ODataTestEntity.h"

ODataTestController1::ODataTestController1()
{

}

void ODataTestController1::get(QMap<QString, QVariant> keys, QUrlQuery query) const
{

}

void ODataTestController1::getSet(QMap<QString, ODataFilter> filter, QUrlQuery query) const
{

}

void ODataTestController1::updateSet(QList<ODataEntity> changedEntities) const
{

}

void ODataTestController1::deleteSet(QList<ODataEntity> changedEntities) const
{

}

void ODataTestController1::insertSet(QList<ODataEntity> changedEntities) const
{

}

QString ODataTestController1::getName() const
{
    return "TestEntity";
}

ODataEntity *ODataTestController1::getNewEntity() const
{
    return new ODataTestEntity();

}

QString ODataTestController1::getDescription() const
{
    return "Test Entity";

}
