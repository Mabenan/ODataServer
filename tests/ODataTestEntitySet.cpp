/*
 * ODataTestEntitySet.cpp
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#include <ODataTestEntitySet.h>
#include <ODataTestEntity2.h>

void ODataTestEntitySet::getSet(
	QUrlQuery query)
{
	ODataTestEntity *entity1 = new ODataTestEntity();
	entity1->data.insert("Id", 1);
	entity1->data.insert("Field", "Test");
	ODataTestEntity2 * testEntity2 = new ODataTestEntity2();
	testEntity2->data.insert("Id2", 1);
	testEntity2->data.insert("Field2", "asfasfwqer");
	entity1->data.insert("TestEntity2", ODataReference(testEntity2));
	this->entities.append(entity1);
}

void ODataTestEntitySet::updateSet() const
{
}

void ODataTestEntitySet::deleteSet() const
{
}

void ODataTestEntitySet::insertSet() const
{
}

ODataEntity *ODataTestEntitySet::get(QMap<QString, QVariant> keys,
									 QUrlQuery query)
{
	ODataTestEntity *entity1 = new ODataTestEntity();
	ODataTestEntity2 * testEntity2;
	if (keys.contains("Id"))
	{
		switch (keys["Id"].toInt())
		{
		case 1:
			entity1->data.insert("Id", 1);
			entity1->data.insert("Field", "Test");
			testEntity2 = new ODataTestEntity2();
			testEntity2->data.insert("Id2", 1);
			testEntity2->data.insert("Field2", "asfasfwqer");
			entity1->data.insert("TestEntity2", ODataReference(testEntity2));
			break;

		default:
			break;
		}
	}
	return entity1;
}

ODataEntitySet* ODataTestEntitySet::clone() const {
	return new ODataTestEntitySet(*this);
}
