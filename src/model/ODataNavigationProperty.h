/*
 * ODataNavigationProperty.h
 *
 *  Created on: 10.03.2020
 *      Author: drichte
 */

#ifndef REPS_ODATASERVER_SRC_MODEL_ODATANAVIGATIONPROPERTY_H_
#define REPS_ODATASERVER_SRC_MODEL_ODATANAVIGATIONPROPERTY_H_

#include <ODataProperty.h>
#include <ODataEntity.h>
#include <ODataEntitySet.h>

class ODATASERVER_EXPORT ODataNavigationProperty: public ODataProperty {
	Q_OBJECT
public:

	ODataEntity * entity;
	bool multi;

	ODataNavigationProperty(ODataEntity * entity, bool multi,QObject * parent = nullptr);
	virtual ~ODataNavigationProperty();
};

#endif /* REPS_ODATASERVER_SRC_MODEL_ODATANAVIGATIONPROPERTY_H_ */

