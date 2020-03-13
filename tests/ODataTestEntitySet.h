/*
 * ODataTestEntitySet.h
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#ifndef TESTS_TST_ODATAENTITYPLUGIN_ODATATESTENTITYSET_H_
#define TESTS_TST_ODATAENTITYPLUGIN_ODATATESTENTITYSET_H_

#include <model/ODataEntitySet.h>
#include <ODataTestEntity.h>

class ODataTestEntitySet: public ODataEntitySet {
public:
	ODataTestEntitySet() : ODataEntitySet() {
		this->entity = new ODataTestEntity();
		this->name = "TestEntitySet";


	}
	virtual ~ODataTestEntitySet() {
		// TODO Auto-generated destructor stub
	}
	virtual ODataEntitySet * clone() const;
	virtual void getSet(
			QUrlQuery query, QVariantMap head);
	virtual void updateSet(QUrlQuery query, QVariantMap head) const;
	virtual void deleteSet(QUrlQuery query, QVariantMap head) const;
	virtual void insertSet(QUrlQuery query, QVariantMap head) const;
	virtual ODataEntity* get(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head);
};

#endif /* TESTS_TST_ODATAENTITYPLUGIN_ODATATESTENTITYSET_H_ */
