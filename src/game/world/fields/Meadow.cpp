#include "Meadow.h"
#include "GameData.hpp"

Meadow::Meadow(int x, int y, World * world) : Field(x,y, world) {
    this->kind = "meadow";
}

void Meadow::setSoil(const std::string name) {
    int fertility    = GameData::read<int>("materials/soils", name + ".fertility");

    this->soil = Soil(name);
    this->soil.setFertility(fertility);
}

std::string Meadow::getDescription(){
    std::stringstream desc;
    if(this->getSoil().getName() != ""){
        desc << "Soil: " << this->getSoil().getName() << "\n";
        desc << "Fertility: " << this->getSoil().getFertility();
    } else {
        desc << "Barren field";
    }
    desc << getBuildingsDescription();
    return desc.str();
}

void Meadow::randomize(){
    std::string soilKind = Soil::randomizeSoilKind();
    if(soilKind != "")
        setSoil(soilKind);
}
