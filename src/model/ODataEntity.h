#ifndef ODATA_ENTITY_H
#define ODATA_ENTITY_H

#include <ODataServer_global.h>
#include <QObject>
#include <model/ODataProperty.h>
#include <QUrlQuery.h>
#include <QMap>
#include <QVariant>
class ODATASERVER_EXPORT ODataEntity : public QObject
{
    Q_OBJECT
protected:
	QString name;
	QString description;
public:
	QMap<QString, QVariant> data;
	QMap<QString, ODataProperty *> property;
public:

    ODataEntity(QObject * parent = nullptr);

	const QString& getName() const {
		return name;
	}
    virtual QString getDescription() {
    	return this->description;
    }
    virtual void get(QMap<QString, QVariant> keys, QUrlQuery query)  = 0;
    virtual void update() const = 0;
    virtual void deleteEntity() const = 0;
    virtual void insert() const = 0;
};

#endif // !ODATA_ENTITY_H
