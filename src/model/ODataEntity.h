#ifndef ODATA_ENTITY_H
#define ODATA_ENTITY_H

#include <ODataServer_global.h>
#include <QObject>
#include <model/ODataProperty.h>
#include <QUrlQuery>
#include <QMap>
#include <QVariant>
#include <variant>
class ODataReference;
class ODATASERVER_EXPORT ODataEntity
{
protected:
	QString name;
	QString description;
public:
	QMap<QString, std::variant<int, float, QVariant, ODataReference>> data;
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
    virtual void get(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head)  = 0;
    virtual void update(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head) const = 0;
    virtual void deleteEntity(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head) const = 0;
    virtual void insert(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head) const = 0;

    QJsonObject toJSON();
};

#endif // !ODATA_ENTITY_H
