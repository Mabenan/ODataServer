/*
 * ODataTestEntitySet2.cpp
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#include <ODataTestEntitySet2.h>

void ODataTestEntitySet2::getSet(
		QUrlQuery query, QVariantMap head) {

}

void ODataTestEntitySet2::updateSet(QUrlQuery query, QVariantMap head) const {
}

void ODataTestEntitySet2::deleteSet(QUrlQuery query, QVariantMap head) const {
}

void ODataTestEntitySet2::insertSet(QUrlQuery query, QVariantMap head) const {
}

ODataEntity* ODataTestEntitySet2::get(QMap<QString, QVariant> keys,
		QUrlQuery query, QVariantMap head) {
	return nullptr;
}

ODataEntitySet* ODataTestEntitySet2::clone() const {
	return new ODataTestEntitySet2(*this);
}
