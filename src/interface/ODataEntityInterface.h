#ifndef ODATA_ENTITY_INTERFACE_H
#define ODATA_ENTITY_INTERFACE_H

#include <model/ODataEntity.h>
#include <model/ODataEntitySet.h>
#include <model/ODataModel.h>
#include <model/ODataSchema.h>
#include <request/ODataFilter.h>
#include <ODataServer_global.h>
#include <QObject>
#include <QUrlQuery>
#include <QtPlugin>

#define ODataEntityInterface_iid "com.odataserver.ODataEntityInterface/1.0"
class ODATASERVER_EXPORT ODataEntityInterface : public QObject
{
    Q_OBJECT

public:

    ODataEntityInterface(QObject * parent) : QObject(parent)
    {

    }
    virtual ~ODataEntityInterface() {}
    virtual QList<ODataSchema *> GetSchemas() = 0;

};

Q_DECLARE_INTERFACE(ODataEntityInterface, "com.odataserver.ODataEntityInterface")

#endif // !ODATA_ENTITY_INTERFACE_H
