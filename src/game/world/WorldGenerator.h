#pragma once

#include "World.h"

enum class TileKind{
    Meadow, Water, SIZE
};

class WorldGenerator {
public:
    static std::shared_ptr<World> generate();
    static std::shared_ptr<World> generate(int width, int height);
private:
    static TileKind randomizeTileKind();
};
