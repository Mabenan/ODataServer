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
	ODataTestEntitySet(QObject * parent = nullptr) : ODataEntitySet(parent) {
		this->entity = new ODataTestEntity(this);
		this->name = "TestEntitySet";


	}
	virtual ~ODataTestEntitySet() {
		// TODO Auto-generated destructor stub
	}

	virtual void getSet(
			QUrlQuery query);
	virtual void updateSet() const;
	virtual void deleteSet() const;
	virtual void insertSet() const;
	virtual ODataEntity* get(QMap<QString, QVariant> keys, QUrlQuery query);
};

#endif /* TESTS_TST_ODATAENTITYPLUGIN_ODATATESTENTITYSET_H_ */
