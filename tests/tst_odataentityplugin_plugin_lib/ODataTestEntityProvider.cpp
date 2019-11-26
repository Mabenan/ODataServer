#include <ODataTestEntity.h>
#include <ODataTestEntityProvider.h>
#include <ODataTestEntitySet.h>
#include <ODataTestEntitySet2.h>
#include <QList>
#include <model/ODataEntityContainer.h>
ODataTestEntityProvider::ODataTestEntityProvider(QObject *parent) : ODataEntityInterface(parent)
{

}


QList<ODataSchema*> ODataTestEntityProvider::GetSchemas() {

	ODataEntityContainer * entityContainer1 = new ODataEntityContainer();
	ODataSchema * schema1 = new ODataSchema("Test", entityContainer1);

	entityContainer1->entitySets.insert("TestEntitySet", new ODataTestEntitySet());

	ODataEntityContainer * entityContainer2 = new ODataEntityContainer();
	ODataSchema * schema2 = new ODataSchema("Test2", entityContainer2);
	entityContainer2->entitySets.insert("TestEntity2Set", new ODataTestEntitySet2());

	return QList<ODataSchema*>({schema1,schema2});
}
