/*
 * ODataTestEntitySet2.h
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#ifndef TESTS_TST_ODATAENTITYPLUGIN_ODATATESTENTITYSET2_H_
#define TESTS_TST_ODATAENTITYPLUGIN_ODATATESTENTITYSET2_H_

#include <model/ODataEntitySet.h>
#include <ODataTestEntity2.h>

class ODataTestEntitySet2: public ODataEntitySet {
public:
	ODataTestEntitySet2(QObject * parent = nullptr) : ODataEntitySet(parent) {
		this->entity = new ODataTestEntity2(this);
		this->name = "TestEntity2Set";

	}
	virtual ~ODataTestEntitySet2() {
		// TODO Auto-generated destructor stub
	}

	virtual void getSet(QMap<QString, ODataFilter> filter,
			QUrlQuery query);
	virtual void updateSet() const;
	virtual void deleteSet() const;
	virtual void insertSet() const;
	virtual ODataEntity* get(QMap<QString, QVariant> keys, QUrlQuery query);
};

#endif /* TESTS_TST_ODATAENTITYPLUGIN_ODATATESTENTITYSET2_H_ */
