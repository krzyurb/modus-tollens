#include <iostream>
#include <sstream>
#include "Field.h"

Field::Field(int x, int y, const std::shared_ptr<World>& world) : x(x), y(y), world(world) {}

Field::~Field() {}

void Field::render(Renderer &renderer, bool dark)const {
    renderer.drawField(*this, dark);
}

Field::operator std::string() {
    std::stringstream result;
    result << "(" << x << ", " << y << ") " << kind;
    return result.str();
}

std::string Field::getDescription() {
    return "No info";
}
