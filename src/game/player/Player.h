#pragma once

#include "World.h"
#include "Stock.h"

class Player {
private:
    World * world;
    Stock stock;
public:
    Stock &getStock();
};
