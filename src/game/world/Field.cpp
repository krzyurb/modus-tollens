#include "Field.h"
#include <iostream>

Field::Field(int x, int y, const std::shared_ptr<World>& world) : x(x), y(y), world(world) {}

Field::~Field() {}
