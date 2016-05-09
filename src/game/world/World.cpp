#include "Meadow.h"

World::World() {}

World::~World() {
    for(auto & field : fields)
        delete field;
}

void World::render(Renderer &renderer) {
    renderer.drawWorld(*this);
}