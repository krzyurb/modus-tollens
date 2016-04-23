#include <game/world/fields/Meadow.h>
#include "World.h"
#include "Renderer.h"

World::World() {
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            this->fields.push_back(Meadow(i * 16, j * 16, nullptr));
        }
    }
}

World::~World() {}

void World::render(Renderer &renderer) {
    renderer.drawWorld(*this);
}