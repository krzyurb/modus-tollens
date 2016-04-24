#include "Meadow.h"

World::World() {}

World::~World() {}

void World::render(Renderer &renderer) {
    renderer.drawWorld(*this);
}
