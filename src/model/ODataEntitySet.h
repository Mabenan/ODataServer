/*
 * ODataEntitySet.h
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#ifndef SRC_ODATAENTITYSET_H_
#define SRC_ODATAENTITYSET_H_

#include <model/ODataEntity.h>
#include <qobject.h>
#include <ODataServer_global.h>
#include <request/ODataFilter.h>
#include <QUrlQuery>
#include <QMap>
#include <QVariant>

class ODATASERVER_EXPORT ODataEntitySet: public QObject {
    Q_OBJECT
protected:
 QString name;
 ODataEntity * entity;
public:
 QList<ODataEntity *> entities; //Data part
public:
	ODataEntitySet(QObject * parent = nullptr);
	virtual ~ODataEntitySet();
	QString getName();
    virtual ODataEntity * get(QMap<QString, QVariant> keys, QUrlQuery query)  = 0;
    virtual void getSet(QMap<QString, ODataFilter> filter, QUrlQuery query)  = 0;
    virtual void updateSet() const = 0;
    virtual void deleteSet() const = 0;
    virtual void insertSet() const = 0;
    ODataEntity * getDefaultEntity(){
    	return this->entity;
    }
};

#endif /* SRC_ODATAENTITYSET_H_ */