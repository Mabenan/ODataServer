/*
 * ODataSingleton.h
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#ifndef SRC_ODATASINGLETON_H_
#define SRC_ODATASINGLETON_H_

#include <qobject.h>
#include "ODataEntity.h"
#include "ODataServer_global.h"

class ODATASERVER_EXPORT ODataSingleton: public QObject {
    Q_OBJECT
private:
	QString name;
	ODataEntity * entity;
public:
	ODataSingleton(QString name, QObject * parent = nullptr);
	virtual ~ODataSingleton();
	QString getName();
	ODataEntity * getEntity();
	void setEntity(ODataEntity * entity);
};

#endif /* SRC_ODATASINGLETON_H_ */
