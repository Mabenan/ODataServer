#include "ODataTestEntity.h"

ODataTestEntity::ODataTestEntity(QObject * parent) : ODataEntity(parent) {
    this->name = "TestEntity";
    this->description = "Test Entity";
}
