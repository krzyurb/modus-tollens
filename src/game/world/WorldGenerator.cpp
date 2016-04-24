#include <memory>

#include "GameData.hpp"
#include "Meadow.h"
#include "Water.h"
#include "WorldGenerator.h"

World WorldGenerator::generate(int width, int height) {
    std::shared_ptr<World> world(new World);

    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            switch(randomizeTileKind()){
                case TileKind::Meadow:
                    world->addField(Meadow(i * tileSize(), j * tileSize(), world));
                    break;
                case TileKind::Water:
                    world->addField(Water(i * tileSize(), j * tileSize(), world));
                    break;
            }
        }
    }

    return *world.get();
}

int WorldGenerator::tileSize() {
    return GameData::read<int>("world", "tileSize");
}

TileKind WorldGenerator::randomizeTileKind() {
    int enumSize = (int)TileKind::SIZE;
    return static_cast<TileKind>(rand() % enumSize);
}
