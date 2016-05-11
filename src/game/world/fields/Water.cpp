#include <sstream>
#include "Water.h"

Water::Water(int x, int y, World * world) : Field(x,y, world) {
    this->kind = "water";
}
std::string Water::getDescription(){
    std::stringstream desc;
    desc << "Depth: " << this->getDepth() << "\n";
    desc << "Salinity: " << this->salinity << "\n";

    return desc.str();
}

void Water::randomize(){
    setDepth(rand() % 500);
    setSalinity(rand() % 100);
}