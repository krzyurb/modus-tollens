#include <iostream>

#include "Field.h"

Field::Field(int x, int y, const std::shared_ptr<World>& world) : x(x), y(y), world(world) {}

Field::~Field() {}

void Field::render(Renderer &renderer) {
    renderer.drawField(*this);
}