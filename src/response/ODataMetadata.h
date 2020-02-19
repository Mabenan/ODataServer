/*
 * ODataMetadataObject.h
 *
 *  Created on: 21.11.2019
 *      Author: drichte
 */

#ifndef SRC_RESPONSE_ODATAMETADATA_H_
#define SRC_RESPONSE_ODATAMETADATA_H_

#include <qobject.h>
#include <ODataServer_global.h>
#include <QtXml>
#include <model/ODataEntityContainer.h>
#include <model/ODataSchema.h>
class ODATASERVER_EXPORT ODataMetadata: public QObject {
	Q_OBJECT
private:
	QMap<QString, ODataSchema * > schemas;
public:
	ODataMetadata(QMap<QString, ODataSchema * > schemas, QObject * parent = nullptr) : QObject(parent) {
		this->schemas = schemas;

	}
	virtual ~ODataMetadata() {
		// TODO Auto-generated destructor stub
	}

	QDomDocument * getAsXML();
};

#endif /* SRC_RESPONSE_ODATAMETADATA_H_ */
