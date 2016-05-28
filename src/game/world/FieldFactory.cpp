#include "FieldFactory.h"
#include "GameData.hpp"
#include "Meadow.h"
#include "Water.h"
#include "Forest.h"

FieldFactory::FieldFactory(World * world) : world(world) {
    tileSize = GameData::read<int>("world", "tileSize");
}

std::unique_ptr<Field> FieldFactory::create(TileKind kind, int x, int y) {
    switch(kind){
        case TileKind::Meadow:
            return std::move(std::make_unique<Meadow>(x * tileSize, y * tileSize, world));
        case TileKind::Water:
            return std::move(std::make_unique<Water>(x * tileSize, y * tileSize, world));
        case TileKind::Forest:
            return std::move(std::make_unique<Forest>(x * tileSize, y * tileSize, world));
        default:
            return std::move(std::unique_ptr<Field>(nullptr));
    }
}

