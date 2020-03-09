/*
 * ODataTestEntitySet.cpp
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#include <ODataTestEntitySet.h>

void ODataTestEntitySet::getSet(
	QUrlQuery query)
{
	ODataTestEntity *entity1 = new ODataTestEntity();
	entity1->data.insert("Id", 1);
	entity1->data.insert("Field", "Test");
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
	if (keys.contains("Id"))
	{
		switch (keys["Id"].toInt())
		{
		case 1:
			entity1->data.insert("Id", 1);
			entity1->data.insert("Field", "Test");
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
