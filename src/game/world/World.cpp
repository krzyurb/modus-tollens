#include "Meadow.h"

void World::render(Renderer &renderer) {
    renderer.drawWorld(*this);
}