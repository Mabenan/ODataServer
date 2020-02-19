/*
 * ODataProperty.h
 *
 *  Created on: 22.11.2019
 *      Author: drichte
 */

#ifndef SRC_MODEL_ODATAPROPERTY_H_
#define SRC_MODEL_ODATAPROPERTY_H_

#include <qobject.h>
#include <ODataServer_global.h>

class ODATASERVER_EXPORT ODataProperty: public QObject {
	Q_OBJECT
public:
	QString type;
	bool key;
public:
	ODataProperty(QString type, bool key, QObject * parent = nullptr) : QObject(parent){
		this->type = type;
		this->key = key;
	}
	virtual ~ODataProperty(){

	}
};

#endif /* SRC_MODEL_ODATAPROPERTY_H_ */
