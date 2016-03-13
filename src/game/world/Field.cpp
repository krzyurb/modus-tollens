#include "Field.h"
#include <iostream>

Field::Field(int x, int y, World *world) : x(x), y(y), world(world) {}

Field::~Field() {}
