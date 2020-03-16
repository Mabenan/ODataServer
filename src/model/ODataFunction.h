/*
 * ODataFunctions.h
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#ifndef SRC_ODATAFUNCTION_H_
#define SRC_ODATAFUNCTION_H_

#include <model/ODataEntitySet.h>
#include <model/ODataEntity.h>
#include <qobject.h>
#include <ODataServer_global.h>

class ODATASERVER_EXPORT ODataFunction: public QObject {
    Q_OBJECT
protected:
	QString name;
	ODataEntitySet * entitySetToReturn;
public:
	ODataFunction(QObject* parent = nullptr);
	virtual ~ODataFunction();

	ODataEntitySet* getEntitySetToReturn() const {
		return entitySetToReturn;
	}

	void setEntitySetToReturn(ODataEntitySet* entitySetToReturn) {
		this->entitySetToReturn = entitySetToReturn;
	}

	const QString& getName() const {
		return name;
	}

	virtual ODataEntity * call(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head) const = 0;
};

#endif /* SRC_ODATAFUNCTION_H_ */
