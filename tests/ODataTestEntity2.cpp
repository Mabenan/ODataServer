#include <ODataTestEntity2.h>

ODataTestEntity2::ODataTestEntity2() : ODataEntity() {
    this->name = "TestEntity2";
    this->description = "Test Entity 2";
    this->property.insert("Id2", new ODataProperty("Edm.Int32", true));
    this->property.insert("Field2", new ODataProperty("Edm.Guid", false));
}

void ODataTestEntity2::deleteEntity(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head) const {
}

void ODataTestEntity2::update(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head) const {
}

void ODataTestEntity2::insert(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head) const {
}

void ODataTestEntity2::get(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head) {
}

ODataEntity* ODataTestEntity2::clone() const {
	return new ODataTestEntity2(*this);
}

ODataTestEntity2::ODataTestEntity2(const ODataTestEntity2 &oDataTestEntity2) : ODataEntity(oDataTestEntity2) {
}
