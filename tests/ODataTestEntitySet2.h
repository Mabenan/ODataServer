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
	ODataTestEntitySet2() : ODataEntitySet() {
		this->entity = new ODataTestEntity2();
		this->name = "TestEntity2Set";

	}
	virtual ~ODataTestEntitySet2() {
		// TODO Auto-generated destructor stub
	}

	virtual void getSet(
			QUrlQuery query, QVariantMap head);
	virtual void updateSet(QUrlQuery query, QVariantMap head) const;
	virtual void deleteSet(QUrlQuery query, QVariantMap head) const;
	virtual void insertSet(QUrlQuery query, QVariantMap head) const;
	virtual ODataEntity* get(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head);
	virtual ODataEntitySet* clone() const;
};

#endif /* TESTS_TST_ODATAENTITYPLUGIN_ODATATESTENTITYSET2_H_ */
