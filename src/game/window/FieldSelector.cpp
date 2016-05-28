#include <GameData.hpp>
#include "game/world/World.h"

FieldSelector::FieldSelector(World *world) : world(world) {
    selectedField = world->get(0);
}

Field *FieldSelector::findField(int x, int y)
{
    if(!inRange(x,y)){
        return nullptr;
    }

    int tileSize = GameData::read<int>("world", "tileSize");
    int col = y / tileSize + 1;
    int row = x / tileSize + 1;
    int num = ((row -1) * 30) + col;

    Field *foundField = world->get(num -1);
    selectedField = foundField;

    return foundField;
}

bool FieldSelector::inRange(int x, int y){
    int tileSize = GameData::read<int>("world", "tileSize");
    int width    = GameData::read<int>("world", "width")  * tileSize;
    int height   = GameData::read<int>("world", "height") * tileSize;
    return (x < width && y < height);
}