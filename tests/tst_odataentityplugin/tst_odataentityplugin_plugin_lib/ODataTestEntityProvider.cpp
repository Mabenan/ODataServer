#include <odatatestcontroller1.h>
#include <odatatestcontroller2.h>
#include <ODataTestEntity.h>
#include <ODataTestEntityProvider.h>
#include <ODataTestEntitySet.h>
#include <ODataTestEntitySet2.h>
ODataTestEntityProvider::ODataTestEntityProvider(QObject *parent) : ODataEntityInterface(parent)
{

}

QList<ODataEntityController *> ODataTestEntityProvider::GetEntityControllers() const
{
    return QList<ODataEntityController *>({new ODataTestController1(), new ODataTestController2()});
}

QList<ODataEntitySet *> ODataTestEntityProvider::getEntitySets() const
{
    return QList<ODataEntitySet *>({new ODataTestEntitySet(), new ODataTestEntitySet2()});
}