#include "FieldFactory.h"
#include "GameData.hpp"
#include "Meadow.h"
#include "Water.h"
#include "Forest.h"

FieldFactory::FieldFactory(World * world) : world(world) {
    tileSize = GameData::read<int>("world", "tileSize");
}

Field * FieldFactory::create(TileKind kind, int x, int y) {
    switch(kind){
        case TileKind::Meadow:
            return new Meadow(x * tileSize, y * tileSize, world);
        case TileKind::Water:
            return new Water(x * tileSize, y * tileSize, world);
        case TileKind::Forest:
            return new Forest(x * tileSize, y * tileSize, world);
        default:
            return nullptr;
    }
}

