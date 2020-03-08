/*
 * ODataSchema.cpp
 *
 *  Created on: 21.11.2019
 *      Author: drichte
 */

#include <ODataSchema.h>
#include <QDebug>
ODataSchema::ODataSchema(QString _namespace, ODataEntityContainer * entityContainer,QObject * parent) : QObject(parent) {
	this->_namespace = _namespace;
	this->entityContainer = entityContainer;
}

ODataSchema::~ODataSchema(){

}
