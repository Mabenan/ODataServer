#include <model/ODataEntity.h>
#include <QJsonObject>
#include <QJsonArray>
#include <any>
#include <QJsonValue>
#include <model/ODataReference.h>

ODataEntity::ODataEntity()
{
}

ODataEntity::~ODataEntity()
{
}

ODataEntity::ODataEntity(const ODataEntity &odataEntity)
{
	name = odataEntity.name;
	description = odataEntity.description;
	data = odataEntity.data;
	property = odataEntity.property;
}

QJsonObject ODataEntity::toJSON()
{

	QJsonObject jsonObject;

	for (QString valueKey : this->data.keys())
	{
		std::variant<int, float, QVariant, ODataReference> anyValue = this->data[valueKey];
		if (auto intValue = std::get_if<int>(&anyValue))
		{
			jsonObject[valueKey] = QJsonValue::fromVariant(QVariant::fromValue(*intValue));
		}
		else if (auto floatValue = std::get_if<float>(&anyValue))
		{
			jsonObject[valueKey] = QJsonValue::fromVariant(QVariant::fromValue(*floatValue));
		}
		else if (auto variantValue = std::get_if<QVariant>(&anyValue))
		{
			jsonObject[valueKey] = QJsonValue::fromVariant(*variantValue);
		}
		else if (auto referenceValue = std::get_if<ODataReference>(&anyValue))
		{
			if(referenceValue->multi){
				jsonObject[valueKey] = referenceValue->entitySet->toJSON();
			}else{
				jsonObject[valueKey] = referenceValue->entity->toJSON();
			}
		}
	}

	return jsonObject;
}
