/*
 * ODataEntitySet.cpp
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#include <model/ODataEntitySet.h>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

ODataEntitySet::ODataEntitySet(QObject* parent) : QObject(parent) {
	this->name = "";
	this->entity = nullptr;
}

ODataEntitySet::~ODataEntitySet() {
	// TODO Auto-generated destructor stub
}

QString ODataEntitySet::getName() {
	return this->name;
}

QJsonObject ODataEntitySet::toJSON() {

	QJsonObject jsonObject;
	QJsonArray value;
	for(ODataEntity * subEntity : this->entities){
		QJsonObject subJsonObject = subEntity->toJSON();
		value.append(subJsonObject);
	}
	jsonObject.insert("value", value);
	return jsonObject;

}
