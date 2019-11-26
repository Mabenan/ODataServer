/*
 * ODataSchema.h
 *
 *  Created on: 21.11.2019
 *      Author: drichte
 */

#ifndef SRC_MODEL_ODATASCHEMA_H_
#define SRC_MODEL_ODATASCHEMA_H_

#include <qobject.h>
#include <model/ODataEntityContainer.h>

class ODATASERVER_EXPORT ODataSchema: public QObject {
	Q_OBJECT
public:
	QString _namespace;
	ODataEntityContainer *entityContainer;
public:
	ODataSchema(QString _namespace, ODataEntityContainer *entityContainer,
			QObject *parent = nullptr);
	virtual ~ODataSchema();

	QString& getNamespace() {
		return _namespace;
	}

	ODataEntityContainer*& getEntityContainer() {
		return entityContainer;
	}
};

#endif /* SRC_MODEL_ODATASCHEMA_H_ */
