#include <sstream>
#include "Mountains.h"

Mountains::Mountains(int x, int y, World *world) : Field(x, y, world) {
    this->kind = "mountains";
}

std::string Mountains::getDescription() {
    std::stringstream desc;
    desc << "Stones: " << this->getStoneCount() << "\n";
    desc << getBuildingsDescription();
    return desc.str();
}

void Mountains::randomize() {
    setStoneCount(rand() % 500);
}

void Mountains::mineStone(int count) {
    stoneCount -= count;
}
