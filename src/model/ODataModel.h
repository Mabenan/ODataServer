#ifndef ODATA_MODEL_H
#define ODATA_MODEL_H

#include <model/ODataEntitySet.h>
#include <ODataServer_global.h>
#include <QObject>
#include <QMap>
#include <QString>
#include <response/ODataServiceDocument.h>
#include <response/ODataMetadata.h>
#include <model/ODataSchema.h>
#include <QList>

class ODATASERVER_EXPORT ODataModel : public QObject
{
    Q_OBJECT
private:
QMap<QString, ODataSchema * > schemas;
QString host;
QString base;
void ensureSchemas();
public:

    ODataModel(QString host, QString base,QObject * parent = nullptr);

    QMap<QString,  ODataEntitySet *> getEntitySets();

    ODataServiceDocument * getServiceDocument();
    ODataMetadata * getMetadata();
};

#endif // !ODATA_MODEL_H

