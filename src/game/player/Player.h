#pragma once

#include "Observer.h"
#include "World.h"
#include "Stock.h"
#include "Renderer.h"

class World;
class Stock;
class Renderer;

class Player : public Observer {
private:
    World * world;
    Stock stock;
public:
    Player();
    const Stock &getStock() const;
    void render(Renderer & renderer);
    void update(Observable * o);
    void gather();
};