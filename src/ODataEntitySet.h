/*
 * ODataEntitySet.h
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#ifndef SRC_ODATAENTITYSET_H_
#define SRC_ODATAENTITYSET_H_

#include <qobject.h>
#include "ODataEntity.h"
#include "ODataServer_global.h"

class ODATASERVER_EXPORT ODataEntitySet: public QObject {
    Q_OBJECT
protected:
 QString name;
 ODataEntity * entity;
public:
	ODataEntitySet(QObject * parent = nullptr);
	virtual ~ODataEntitySet();
	QString getName();
	ODataEntity * getEntity();
};

#endif /* SRC_ODATAENTITYSET_H_ */
