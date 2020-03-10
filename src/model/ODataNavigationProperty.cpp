/*
 * ODataNavigationProperty.cpp
 *
 *  Created on: 10.03.2020
 *      Author: drichte
 */

#include <model/ODataNavigationProperty.h>

ODataNavigationProperty::ODataNavigationProperty(ODataEntity *entity, bool multi, QObject* parent) : ODataProperty("Nav", false, parent) {
	this->entity = entity;
	this->multi = multi;
}

ODataNavigationProperty::~ODataNavigationProperty() {
	// TODO Auto-generated destructor stub
}

