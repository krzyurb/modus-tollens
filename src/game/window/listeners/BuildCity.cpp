#include <string>
#include <iostream>
#include <game/world/fields/City.h>
#include "BuildCity.h"


void BuildCity::perform() {
    std::cout << "Builded City!" << std::endl;
//    Field * city = new City(getField()->getX(), getField()->getY(),getField()->getWorld());
//    getField()->getWorld()[getField()->getId()] = city;
    getField()->setKind("water");
    std::cout << getField()->getKind();
}

BuildCity::BuildCity(Field *field) : field(field) {}
