#include <string>
#include <iostream>
#include <game/world/fields/City.h>
#include "BuildCity.h"


void BuildCity::perform() {
    std::cout << "Builded City!" << std::endl;
    Field * field = getFieldSelector()->getSelectedField();
    Field * city = new City(field->getX(), field->getY(), field->getWorld());
    getFieldSelector()->getSelectedField()->getWorld()->setField(getFieldSelector()->getSelectedField()->getId(), city);
}

BuildCity::BuildCity(FieldSelector *fieldSelector) : fieldSelector(fieldSelector) {}
