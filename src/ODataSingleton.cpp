/*
 * ODataSingleton.cpp
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#include <ODataSingleton.h>


ODataSingleton::ODataSingleton(QString name, QObject * parent) : QObject(parent) {
	this->name = name;
	this->entity = nullptr;
}

ODataSingleton::~ODataSingleton() {
	// TODO Auto-generated destructor stub
}

QString ODataSingleton::getName() {
	return this->name;
}

ODataEntity* ODataSingleton::getEntity() {
	return this->entity;
}

void ODataSingleton::setEntity(ODataEntity* entity) {
	this->entity = entity;
}
