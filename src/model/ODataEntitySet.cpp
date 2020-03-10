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
#include <model/ODataEntity.h>
ODataEntitySet::ODataEntitySet() {
	this->name = "";
	this->entity = nullptr;
}

ODataEntitySet::~ODataEntitySet() {

}

QString ODataEntitySet::getName() {
	return this->name;
}

ODataEntitySet::ODataEntitySet(const ODataEntitySet &odataEntitySet) {
	this->entity = odataEntitySet.entity->clone();
	this->name = odataEntitySet.name;
	this->entities = odataEntitySet.entities;
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
