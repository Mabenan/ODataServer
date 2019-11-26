/*
 * ODataEntitySet.cpp
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#include <model/ODataEntitySet.h>

ODataEntitySet::ODataEntitySet(QObject* parent) : QObject(parent) {
	this->name = "";
	this->entity = nullptr;
}

ODataEntitySet::~ODataEntitySet() {
	// TODO Auto-generated destructor stub
}

QString ODataEntitySet::getName() {
	return this->name;
}
