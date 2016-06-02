#include "FieldFactory.h"
#include "GameData.hpp"
#include "Meadow.h"
#include "Water.h"
#include "Forest.h"
#include "Mountains.h"

FieldFactory::FieldFactory(World * world) : world(world) {
    tileSize = GameData::read<int>("world", "tileSize");
}

std::unique_ptr<Field> FieldFactory::create(TileKind kind, int x, int y) {
    switch(kind){
        case TileKind::Meadow:
            return std::make_unique<Meadow>(x * tileSize, y * tileSize, world);
        case TileKind::Water:
            return std::make_unique<Water>(x * tileSize, y * tileSize, world);
        case TileKind::Forest:
            return std::make_unique<Forest>(x * tileSize, y * tileSize, world);
        case TileKind::Mountains:
            return std::make_unique<Mountains>(x * tileSize, y * tileSize, world);
        default:
            return std::unique_ptr<Field>(nullptr);
    }
}

