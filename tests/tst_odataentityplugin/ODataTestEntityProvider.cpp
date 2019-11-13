#include "ODataTestEntityProvider.h"
#include "ODataTestEntity.h"
#include "odatatestcontroller1.h"
#include "odatatestcontroller2.h"

ODataTestEntityProvider::ODataTestEntityProvider(QObject *parent) : ODataEntityInterface(parent)
{

}

QList<ODataEntityController *> ODataTestEntityProvider::GetEntityControllers() const
{
    return QList<ODataEntityController *>({new ODataTestController1(), new ODataTestController2()});
}
