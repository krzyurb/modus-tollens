#include "Meadow.h"
#include "GameData.hpp"

Meadow::Meadow(int x, int y, const std::shared_ptr<World>& world) : Field(x,y, world) {
    this->kind = "meadow";
}

void Meadow::setSoil(const std::string name) {
    int fertility    = GameData::read<int>("materials/soils", name + ".fertility");
    std::string kind = GameData::read<std::string>("materials/soils", name + ".kind");

    this->soil = Soil(name);
    this->soil.setFertility(fertility);
}

std::string Meadow::getDescription(){
    std::stringstream desc;
    if(this->getSoil().getName() != ""){
        desc << "Soil: " << this->getSoil().getName();
        desc << "(" << this->getSoil().getFertility() << ")";
    } else {
        desc << "Barren field";
    }
    return desc.str();
}

void Meadow::randomize(){

}