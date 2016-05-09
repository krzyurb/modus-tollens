#include <memory>

#include "GameData.hpp"
#include "WorldGenerator.h"
#include "FieldFactory.h"

std::shared_ptr<World> WorldGenerator::generate() {
    int width  = GameData::read<int>("world", "width");
    int height = GameData::read<int>("world", "height");

    return generate(width, height);
}

std::shared_ptr<World> WorldGenerator::generate(int width, int height) {
    std::shared_ptr<World> world = std::make_shared<World>();
    FieldFactory fieldFactory(world);

    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            Field *field = fieldFactory.create(randomizeTileKind(), i, j);
            field->randomize();
            world->addField(field);
        }
    }

    return world;
}

TileKind WorldGenerator::randomizeTileKind() {
    int enumSize = (int)TileKind::SIZE;
    return static_cast<TileKind>(rand() % enumSize);
}
