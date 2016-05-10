#pragma once

#include <game/world/Field.h>

class City : public Field {
public:
    City(int x, int y, const std::shared_ptr<World> &world);
};
