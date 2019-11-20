#include <odatatestcontroller2.h>
#include <ODataTestEntitySet2.h>

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
ODataEntitySet *ODataTestController2::getEntitySet()
{
    return new ODataTestEntitySet2(this);

}
