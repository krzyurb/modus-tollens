#include <game/world/fields/Meadow.h>
#include "World.h"
#include "Renderer.h"

World::World(int width, int height) {
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            this->fields.push_back(Meadow(i * 16, j * 16, nullptr));
        }
    }
}

World::~World() {}

void World::render(Renderer &renderer) {
    renderer.drawWorld(*this);
}
