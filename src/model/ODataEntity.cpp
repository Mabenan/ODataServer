#include <model/ODataEntity.h>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

ODataEntity::ODataEntity() {
    

}

ODataEntity::~ODataEntity() {

}

ODataEntity::ODataEntity(const ODataEntity &odataEntity) {
 name = odataEntity.name;
 description = odataEntity.description;
 data = odataEntity.data;
 property = odataEntity.property;
}

QJsonObject ODataEntity::toJSON() {

	QJsonObject jsonObject;

	for(QString valueKey : this->data.keys()){
		jsonObject[valueKey] = QJsonValue::fromVariant(this->data[valueKey]);
	}

	return jsonObject;

}
