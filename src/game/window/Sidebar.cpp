#include <GameData.hpp>
#include <game/timing/Calendar.h>
#include "Sidebar.h"

void Sidebar::render(Renderer &renderer) {
    renderer.drawSidebar(*this);
}

Sidebar::Sidebar(Calendar *calendar) {
    int worldWidth = GameData::read<int>("world", "width");
    int tileSize   = GameData::read<int>("world", "tileSize");
    this->x        = worldWidth * tileSize + 10;
    this->calendar = calendar;
}