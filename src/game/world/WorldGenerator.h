#pragma once

#include "World.h"

enum class TileKind{
    Meadow, Water, Forest, Mountains, SIZE
};

class WorldGenerator {
public:
    static std::unique_ptr<World> generate();
    static std::unique_ptr<World> generate(int width, int height);
private:
    static TileKind randomizeTileKind();
};
