#pragma once

#include "World.h"

enum class TileKind{
    Meadow, Water, SIZE
};

class WorldGenerator {
public:
    static World generate(int width, int height);
private:
    static int tileSize();
    static TileKind randomizeTileKind();
};
