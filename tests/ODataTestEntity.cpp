#include <ODataTestEntity.h>
#include <model/ODataProperty.h>
#include <ODataTestEntity2.h>
#include <model/ODataNavigationProperty.h>

ODataTestEntity::ODataTestEntity() : ODataEntity() {
    this->name = "TestEntity";
    this->description = "Test Entity";
    this->property.insert("Id", new ODataProperty("Edm.Int32", true));
    this->property.insert("Field", new ODataProperty("Edm.String", false));
    this->property.insert("TestEntity2", new ODataNavigationProperty(new ODataTestEntity2(), false));
}
void ODataTestEntity::deleteEntity() const {
}

void ODataTestEntity::update() const {
}

void ODataTestEntity::insert() const {
}

void ODataTestEntity::get(QMap<QString, QVariant> keys, QUrlQuery query) {
}

ODataEntity* ODataTestEntity::clone() const {
	return new ODataTestEntity(*this);
}

ODataTestEntity::ODataTestEntity(const ODataTestEntity &oDataTestEntity) : ODataEntity(oDataTestEntity) {
}
