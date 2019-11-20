#ifndef ODATA_MODEL_H
#define ODATA_MODEL_H

#include "ODataServer_global.h"
#include <QObject>
#include <QMap>
#include <QString>
#include "ODataServiceDocument.h"

#include "ODataEntitySet.h"
class ODATASERVER_EXPORT ODataModel : public QObject
{
    Q_OBJECT
private:
QMap<QString,  ODataEntitySet *> entitySets;
QString host;
QString base;
public:

    ODataModel(QString host, QString base,QObject * parent = nullptr);

    QMap<QString,  ODataEntitySet *> getEntitySets();

    ODataServiceDocument * getServiceDocument();

};

#endif // !ODATA_MODEL_H

