#pragma once

#include <string>
#include "World.h"

class Field {
public:
    Field(int x, int y, World *world = nullptr);
    virtual ~Field();

private:
    int x, y;
    std::string kind;
    std::unique_ptr<World> world;
};
