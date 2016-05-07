#include <GameData.hpp>
#include "Sidebar.h"

void Sidebar::render(Renderer &renderer) {
    renderer.drawSidebar(*this);
}

Sidebar::Sidebar() {
    int worldWidth  = GameData::read<int>("world", "width");
    int tileSize    = GameData::read<int>("world", "tileSize");
    x = worldWidth * tileSize + 10;
}
