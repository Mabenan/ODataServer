/*
 * ODataFunctions.cpp
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#include <ODataFunction.h>

ODataFunction::ODataFunction(QObject * parent): QObject(parent){
	this->entitySetToReturn = nullptr;
}

ODataFunction::~ODataFunction() {
	// TODO Auto-generated destructor stub
}

