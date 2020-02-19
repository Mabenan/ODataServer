#include <ODataTestEntity2.h>

ODataTestEntity2::ODataTestEntity2(QObject * parent) : ODataEntity(parent) {
    this->name = "TestEntity2";
    this->description = "Test Entity 2";
    this->property.insert("Id2", new ODataProperty("Edm.Int32", true));
    this->property.insert("Field2", new ODataProperty("Edm.Guid", false));
}

void ODataTestEntity2::deleteEntity() const {
}

void ODataTestEntity2::update() const {
}

void ODataTestEntity2::insert() const {
}

void ODataTestEntity2::get(QMap<QString, QVariant> keys, QUrlQuery query) {
}
