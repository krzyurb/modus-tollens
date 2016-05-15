#pragma once

#include "World.h"
#include "Stock.h"
#include "Renderer.h"

class World;
class Stock;
class Renderer;

class Player {
private:
    World * world;
    Stock stock;
public:
    const Stock &getStock() const;
    void render(Renderer & renderer);
};