/*
 * ODataReference.h
 *
 *  Created on: 10.03.2020
 *      Author: drichte
 */

#ifndef REPS_ODATASERVER_SRC_MODEL_ODATAREFERENCE_H_
#define REPS_ODATASERVER_SRC_MODEL_ODATAREFERENCE_H_

#include <model/ODataEntity.h>
#include <model/ODataEntitySet.h>

class ODATASERVER_EXPORT ODataReference {
public:

	ODataEntity * entity;
	ODataEntitySet * entitySet;
	bool multi;

	ODataReference(ODataEntity * entity);
	ODataReference(ODataEntitySet * entitySet);
	ODataReference(const ODataReference &odataReference);
	virtual ~ODataReference();
};

#endif /* REPS_ODATASERVER_SRC_MODEL_ODATAREFERENCE_H_ */
