/*
 * ODataSchema.cpp
 *
 *  Created on: 21.11.2019
 *      Author: drichte
 */

#include <ODataSchema.h>

ODataSchema::ODataSchema(QString _namespace, ODataEntityContainer * entityContainer,QObject * parent) : QObject(parent) {
	this->_namespace = _namespace;
	this->entityContainer = entityContainer;
}

ODataSchema::~ODataSchema() {
	// TODO Auto-generated destructor stub
}

