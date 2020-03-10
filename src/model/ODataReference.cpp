/*
 * ODataReference.cpp
 *
 *  Created on: 10.03.2020
 *      Author: drichte
 */

#include <ODataReference.h>

ODataReference::ODataReference(ODataEntity *entity) {
	this->entity = entity;
	this->entitySet = nullptr;
	this->multi = false;
}

ODataReference::ODataReference(ODataEntitySet *entitySet) {
	this->entitySet = entitySet;
	this->entity = nullptr;
	this->multi = true;
}

ODataReference::~ODataReference() {
	// TODO Auto-generated destructor stub
}

ODataReference::ODataReference(const ODataReference &odataReference) {
	this->entity = odataReference.entity;
	this->entitySet = odataReference.entitySet;
	this->multi = odataReference.multi;

}
