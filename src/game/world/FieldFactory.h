#pragma once

#include "World.h"
#include "WorldGenerator.h"

class FieldFactory {
private:
    size_t tileSize;
    World * world;
public:
    FieldFactory(World * world);
    std::unique_ptr<Field> create(TileKind kind, int x, int y);
};
