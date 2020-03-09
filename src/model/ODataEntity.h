#ifndef ODATA_ENTITY_H
#define ODATA_ENTITY_H

#include <ODataServer_global.h>
#include <QObject>
#include <model/ODataProperty.h>
#include <QUrlQuery>
#include <QMap>
#include <QVariant>
class ODATASERVER_EXPORT ODataEntity
{
protected:
	QString name;
	QString description;
public:
	QMap<QString, QVariant> data;
	QMap<QString, ODataProperty *> property;
public:

    ODataEntity();
    virtual ~ODataEntity();
    ODataEntity(const ODataEntity &odataEntity);
	const QString& getName() const {
		return name;
	}
    virtual QString getDescription() {
    	return this->description;
    }
    virtual ODataEntity * clone() const = 0;
    virtual void get(QMap<QString, QVariant> keys, QUrlQuery query)  = 0;
    virtual void update() const = 0;
    virtual void deleteEntity() const = 0;
    virtual void insert() const = 0;

    QJsonObject toJSON();
};

#endif // !ODATA_ENTITY_H
