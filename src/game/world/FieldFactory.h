#pragma once

#include "World.h"
#include "WorldGenerator.h"

class FieldFactory {
private:
    size_t tileSize;
    std::shared_ptr<World> world;
public:
    FieldFactory(std::shared_ptr<World> & world);
    Field * create(TileKind kind, int x, int y);
};
