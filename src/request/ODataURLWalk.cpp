/*
 * ODataURLWalk.cpp
 *
 *  Created on: 15.02.2020
 *      Author: daniel
 */

#include <ODataURLWalk.h>

ODataURLWalk::ODataURLWalk(ODataModel *model, QUrl url, QUrlQuery query, QVariant body, QObject *parent) :
		QObject(parent) {
	this->model = model;
}

QVariant ODataURLWalk::walkURL(QStringList segments) {

	bool finished = false;
	bool error = false;

	while (!finished && !error) {
		QString currentSegment = segments[this->currentPathIndex];
		QStringList resourceParts = currentSegment.split('(');
		QString prePossibleKey = resourceParts[0];
		QStringList resourceSegments = prePossibleKey.split('.');
		QString entity = resourceSegments.last();
		QString ns = "";
		for (int i = 0; i < resourceSegments.size() - 1; i++) {
			ns += resourceSegments[i];
			if (i < resourceSegments.size() - 2) {
				ns += '.';
			}
		}
		ODataSchema *schema = nullptr;
		if (ns != "") {
			schema = this->model->schemas[ns];
		} else {
			schema = this->model->schemas["default"];
		}
		ODataEntity * entityObject = schema->getEntityContainer()->entitySets[entity];

	}

	return this->currentResult;
}
