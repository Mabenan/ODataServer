/*
 * ODataTestEntitySet.h
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#ifndef TESTS_TST_ODATAENTITYPLUGIN_ODATATESTENTITYSET_H_
#define TESTS_TST_ODATAENTITYPLUGIN_ODATATESTENTITYSET_H_

#include <ODataEntitySet.h>
#include <ODataTestEntity.h>

class ODataTestEntitySet: public ODataEntitySet {
public:
	ODataTestEntitySet(QObject * parent = nullptr) : ODataEntitySet(parent) {
		this->entity = new ODataTestEntity(this);
		this->name = "TestEntitySet";


	}
	virtual ~ODataTestEntitySet() {
		// TODO Auto-generated destructor stub
	}
};

#endif /* TESTS_TST_ODATAENTITYPLUGIN_ODATATESTENTITYSET_H_ */
