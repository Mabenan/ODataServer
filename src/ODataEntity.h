#ifndef ODATA_ENTITY_H
#define ODATA_ENTITY_H

#include "ODataServer_global.h"
#include <QObject>

class ODATASERVER_EXPORT ODataEntity : public QObject
{
    Q_OBJECT

public:

    ODataEntity(QObject * parent = nullptr);



};

#endif // !ODATA_ENTITY_H