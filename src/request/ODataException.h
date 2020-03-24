/*
 * ODataException.h
 *
 *  Created on: 23.03.2020
 *      Author: drichte
 */

#ifndef REPS_ODATASERVER_SRC_REQUEST_ODATAEXCEPTION_H_
#define REPS_ODATASERVER_SRC_REQUEST_ODATAEXCEPTION_H_

#include <exception>
#include <ODataServer_global.h>
#include <QVariant>

class ODataException: public std::exception {
public:
	QVariant errorBody;
	const char * msg;
	ODataException(const char * msg, QVariant errorBody);
    virtual const char* what() const throw () {
       return msg;
    }
	virtual ~ODataException();
};

#endif /* REPS_ODATASERVER_SRC_REQUEST_ODATAEXCEPTION_H_ */
