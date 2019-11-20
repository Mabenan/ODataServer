/*
 * ODataAction.h
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#ifndef SRC_ODATAACTION_H_
#define SRC_ODATAACTION_H_

#include <qobject.h>
#include "ODataServer_global.h"

class ODATASERVER_EXPORT ODataAction: public QObject {
    Q_OBJECT
protected:
 QString name;

public:
	ODataAction(QObject * parent = nullptr): QObject(parent) {

	}
	virtual ~ODataAction() {
		// TODO Auto-generated destructor stub
	}
	virtual void call() const = 0;

	const QString& getName() const {
		return name;
	}
};

#endif /* SRC_ODATAACTION_H_ */
