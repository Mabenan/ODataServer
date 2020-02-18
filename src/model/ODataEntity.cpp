#include <model/ODataEntity.h>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

ODataEntity::ODataEntity(QObject * parent) : QObject(parent) {
    

}

QJsonObject ODataEntity::toJSON() {

	QJsonObject jsonObject;

	for(QString valueKey : this->data.keys()){
		jsonObject[valueKey] = QJsonValue::fromVariant(this->data[valueKey]);
	}

	return jsonObject;

}
