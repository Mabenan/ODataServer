#ifndef ODATA_ENTITY_INTERFACE_H
#define ODATA_ENTITY_INTERFACE_H

#include "ODataServer_global.h"
#include <QObject>
#include <QUrlQuery>
#include "ODataModel.h"
#include "ODataFilter.h"
#include "ODataEntity.h"
#include <QtPlugin>
#include "odataentitycontroller.h"
#include "ODataEntitySet.h"

#define ODataEntityInterface_iid "com.odataserver.ODataEntityInterface/1.0"
class ODATASERVER_EXPORT ODataEntityInterface : public QObject
{
    Q_OBJECT

public:

    ODataEntityInterface(QObject * parent) : QObject(parent)
    {

    }
    virtual ~ODataEntityInterface() {}
    virtual QList<ODataEntityController *> GetEntityControllers() const = 0;
    virtual QList<ODataEntitySet *> getEntitySets() const = 0;

};

Q_DECLARE_INTERFACE(ODataEntityInterface, "com.odataserver.ODataEntityInterface")

#endif // !ODATA_ENTITY_INTERFACE_H
