#include <memory>

#include "GameData.hpp"
#include "WorldGenerator.h"
#include "FieldFactory.h"

World WorldGenerator::generate(int width, int height) {
    std::shared_ptr<World> world(new World);
    FieldFactory fieldFactory(world);

    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            world->addField(fieldFactory.create(randomizeTileKind(), i, j));
        }
    }

    return *world.get();
}



TileKind WorldGenerator::randomizeTileKind() {
    int enumSize = (int)TileKind::SIZE;
    return static_cast<TileKind>(rand() % enumSize);
}
