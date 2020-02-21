/*
 * ODataMetadataObject.cpp
 *
 *  Created on: 21.11.2019
 *      Author: drichte
 */

#include <ODataMetadata.h>

QDomDocument * ODataMetadata::getAsXML() {

	QDomDocument * doc = new QDomDocument();

	QDomElement root = doc->createElementNS("http://docs.oasis-open.org/odata/ns/edmx", "edmx:Edmx");
	root.setAttribute("Version", "4.0");

	QDomElement dataServices = doc->createElement("edmx:DataServices");

	for(QString _namespace : this->schemas.keys()){
		QDomElement schema = doc->createElementNS("http://docs.oasis-open.org/odata/ns/edm", "Schema");
		schema.setAttribute("Namespace", _namespace);
	    ODataEntityContainer * entityContainer =  this->schemas[_namespace]->getEntityContainer();
	    QDomElement eCElement = doc->createElement("EntityContainer");
	    eCElement.setAttribute("Name", "Container");
	    for(QString entitySetName : entityContainer->entitySets.keys()){
	    	ODataEntitySet * entitySet = entityContainer->entitySets[entitySetName];
	    	ODataEntity * entity = entitySet->getDefaultEntity();

	    	QDomElement entitySetElement = doc->createElement("EntitySet");
	    	entitySetElement.setAttribute("Name", entitySet->getName());
	    	entitySetElement.setAttribute("EntityType", _namespace + "." + entity->getName());
	    	eCElement.appendChild(entitySetElement);

	    	QDomElement entityElement = doc->createElement("EntityType");
	    	entityElement.setAttribute("Name", entity->getName());
	    	QDomElement entityKeyElement = doc->createElement("Key");
	    	for(QString property : entity->property.keys()){
	    		QDomElement entityPropElement = doc->createElement("Property");
	    		entityPropElement.setAttribute("Name", property);
	    		entityPropElement.setAttribute("Type", entity->property[property]->type);
	    		if(entity->property[property]->key){
	    			QDomElement propertyRefElement = doc->createElement("PropertyRef");
	    			propertyRefElement.setAttribute("Name", property);
	    			entityKeyElement.appendChild(propertyRefElement);
	    		}
	    		entityElement.appendChild(entityPropElement);
	    	}
	    	entityElement.appendChild(entityKeyElement);

	    	schema.appendChild(entityElement);

	    }
	    schema.appendChild(eCElement);
	    dataServices.appendChild(schema);
	}
	root.appendChild(dataServices);
	doc->appendChild(root);


	return doc;
}
