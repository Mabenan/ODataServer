#ifndef ODATA_MODEL_H
#define ODATA_MODEL_H

#include "ODataServer_global.h"
#include <QObject>
#include <QMap>
#include <QString>

class ODataEntityController;

class ODATASERVER_EXPORT ODataModel : public QObject
{
    Q_OBJECT
private:
QMap<QString, ODataEntityController *> entities;
public:

    ODataModel(QObject * parent = nullptr);

    QMap<QString, ODataEntityController *> getEntities();

};

#endif // !ODATA_MODEL_H
