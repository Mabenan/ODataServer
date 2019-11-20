#ifndef ODATA_ENTITY_H
#define ODATA_ENTITY_H

#include <ODataServer_global.h>
#include <QObject>

class ODATASERVER_EXPORT ODataEntity : public QObject
{
    Q_OBJECT
protected:
	QString name;
	QString description;
public:

    ODataEntity(QObject * parent = nullptr);

	const QString& getName() const {
		return name;
	}
    virtual QString getDescription() {
    	return this->description;
    }
};

#endif // !ODATA_ENTITY_H
