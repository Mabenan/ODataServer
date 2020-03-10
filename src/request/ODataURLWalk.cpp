/*
 * ODataURLWalk.cpp
 *
 *  Created on: 15.02.2020
 *      Author: daniel
 */

#include <ODataURLWalk.h>
#include <request/odatarequesthandler.h>
#include <model/ODataReference.h>

ODataURLWalk::ODataURLWalk(ODataModel *model, QUrl url, QUrlQuery query, QVariant body, ODataRequestHandler::Method method, QObject *parent) : QObject(parent)
{
	this->model = model;
	this->url = url;
	this->query = query;
	this->body = body;
	this->method = method;
	this->lastEntity = nullptr;
}

QVariant ODataURLWalk::walkURL(QStringList segments)
{

	bool finished = false;
	bool error = false;
	QMap<QString, ODataEntitySet *> entitySets = model->getEntitySets();
	QMap<QString, ODataAction *> actions = model->getActions();
	QMap<QString, ODataFunction *> functions = model->getFunctions();
	while (!finished && !error)
	{
		QString currentSegment = segments[this->currentPathIndex];
		QStringList resourceParts = currentSegment.split('(');
		QString prePossibleKey = resourceParts[0];
		QMap<QString, QVariant> keys;
		if (resourceParts.length() == 2)
		{
			QString possibleKey = resourceParts[1];
			qDebug() << possibleKey;
			QStringRef keySegment(&possibleKey, 0, resourceParts[1].length() - 1);
			QVector<QStringRef> keyParts = keySegment.split(',');
			for (int keyNumber = 0; keyNumber < keyParts.length(); keyNumber++)
			{
				QStringRef keyPart = keyParts[keyNumber];
				QVector<QStringRef> eachKeyParts = keyPart.split('=');
				QStringRef keyName = eachKeyParts[0];
				QStringRef keyValue = eachKeyParts[1];
				if (keyValue.startsWith("'") && keyValue.endsWith("'"))
				{
					QString keyValueString = keyValue.toString();
					QStringRef keyValue2(&keyValueString, 1, keyValueString.length() - 1);
					keyValue = keyValue2;
				}
				qDebug() << keyName.toString();
				qDebug() << keyValue.toString();
				keys.insert(keyName.toString(), keyValue.toString());
			}
		}
		if(this->lastEntity != nullptr){
			if(this->lastEntity->data.contains(prePossibleKey)){
				std::variant<int, float, QVariant, ODataReference> anyValue = this->lastEntity->data[prePossibleKey];
			if (auto intValue = std::get_if<int>(&anyValue))
			{
				this->currentResult = QJsonValue::fromVariant(QVariant::fromValue(*intValue));
			}
			else if (auto floatValue = std::get_if<float>(&anyValue))
			{
				this->currentResult = QJsonValue::fromVariant(QVariant::fromValue(*floatValue));
			}
			else if (auto variantValue = std::get_if<QVariant>(&anyValue))
			{
				this->currentResult = QJsonValue::fromVariant(*variantValue);
			}
			else if (auto referenceValue = std::get_if<ODataReference>(&anyValue))
			{
				if(referenceValue->multi){
					this->currentResult = referenceValue->entitySet->toJSON();
				}else{
					this->currentResult = referenceValue->entity->toJSON();
					this->lastEntity = referenceValue->entity;
				}
			}
			}else{

				this->currentResult = "Error " + prePossibleKey + " not a property of entity "+ this->lastEntity->getName();
			}
			if (this->currentPathIndex < segments.length() - 1)
			{
				this->currentPathIndex++;
			}
			else
			{
				finished = true;
			}
		}else if (!entitySets.contains(prePossibleKey))
		{
			if (!actions.contains(prePossibleKey))
			{
				if (!functions.contains(prePossibleKey))
				{

					error = true;
					this->currentResult = "Error " + prePossibleKey + " neither a entity, action or function";
				}
				else
				{
					this->currentResult = functions[prePossibleKey]->call()->toJSON();
				}
			}
			else
			{
				actions[prePossibleKey]->call();
				this->currentResult = QJsonObject();
			}
		}
		else
		{
			ODataEntitySet *entitySet = entitySets[prePossibleKey]->clone();
			ODataEntity *entityObject;
			QJsonObject bodyJSON;
			QMap<QString, QVariant> variantMap;
			QVariant::Type bodyType = this->body.type();
			if(bodyType == QVariant::Type::ByteArray){
				QJsonParseError parseError;
				bodyJSON = QJsonDocument::fromJson(body.toByteArray(), &parseError).object();
				qDebug() << parseError.errorString();
			}
			switch (this->method)
			{
			case ODataRequestHandler::Method::GET:

				if (keys.size() > 0)
				{
					entityObject = entitySet->get(keys, this->query);
					this->currentResult = entityObject->toJSON();
					this->lastEntity = entityObject;
				}
				else
				{
					entitySet->getSet(this->query);
					this->currentResult = entitySet->toJSON();
				}
				break;
			case ODataRequestHandler::Method::POST:
				entityObject = entitySet->getDefaultEntity();
				variantMap = bodyJSON.toVariantMap();
				for(QString variantKey : variantMap.keys()){
					QVariant value = variantMap[variantKey];
					entityObject->data.insert(variantKey, value);
				}
				entityObject->insert();
				this->currentResult = entityObject->toJSON();
				this->lastEntity = entityObject;
				break;
			case ODataRequestHandler::Method::PATCH:
				if (keys.size() > 0)
				{
					entityObject = entitySet->get(keys, this->query);
					variantMap = bodyJSON.toVariantMap();
					for(QString variantKey : variantMap.keys()){
						QVariant value = variantMap[variantKey];
						entityObject->data.insert(variantKey, value);
					}
					entityObject->update();
					this->currentResult = entityObject->toJSON();
					this->lastEntity = entityObject;
				}
				else
				{
					error = true;
					this->currentResult = "no key given for update";
				}

				break;
			case ODataRequestHandler::Method::DELETE:
				if (keys.size() > 0)
				{
					entityObject = entitySet->get(keys, this->query);
					entityObject->deleteEntity();
					this->currentResult = entityObject->toJSON();
					this->lastEntity = entityObject;
				}
				else
				{
					entitySet->getSet(this->query);
					entitySet->deleteSet();
					this->currentResult = entitySet->toJSON();
				}
				break;
			default:
				break;
			}
			if (this->currentPathIndex < segments.length() - 1)
			{
				this->currentPathIndex++;
			}
			else
			{
				finished = true;
			}
		}
	}

	return this->currentResult;
}
