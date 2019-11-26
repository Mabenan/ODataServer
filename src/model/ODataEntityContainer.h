/*
 * ODataEntityContainer.h
 *
 *  Created on: 14.11.2019
 *      Author: drichte
 */

#ifndef SRC_ODATAENTITYCONTAINER_H_
#define SRC_ODATAENTITYCONTAINER_H_

#include <model/ODataAction.h>
#include <model/ODataEntitySet.h>
#include <model/ODataFunction.h>
#include <model/ODataSingleton.h>
#include <qobject.h>
#include <QMap>
#include <ODataServer_global.h>

class ODATASERVER_EXPORT ODataEntityContainer: public QObject {

public:
	QMap<QString, ODataEntitySet *> entitySets;
	QMap<QString, ODataSingleton *> singeltons;
	QMap<QString, ODataFunction *> functions;
	QMap<QString, ODataAction *> actionImports;
public:
	ODataEntityContainer(QObject * parent = nullptr);
	virtual ~ODataEntityContainer();
};

#endif /* SRC_ODATAENTITYCONTAINER_H_ */
