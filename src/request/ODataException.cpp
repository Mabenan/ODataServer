/*
 * ODataException.cpp
 *
 *  Created on: 23.03.2020
 *      Author: drichte
 */

#include <ODataException.h>

ODataException::ODataException(const char * msg, QVariant errorBody){
	this->errorBody = errorBody;
	this->msg = msg;
}

ODataException::~ODataException() {
	// TODO Auto-generated destructor stub
}

