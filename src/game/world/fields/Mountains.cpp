#include <sstream>
#include "Mountains.h"

Mountains::Mountains(int x, int y, World *world) : Field(x, y, world) {}

std::string Mountains::getDescription() {
    std::stringstream desc;
    desc << "Stones: " << this->getStoneCount() << "\n";

    return desc.str();
}

void Mountains::randomize() {
    setStoneCount(rand() % 500);
}
