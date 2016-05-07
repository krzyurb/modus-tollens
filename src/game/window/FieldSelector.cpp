#include <GameData.hpp>
#include "game/world/World.h"

FieldSelector::FieldSelector(World *world) : world(world) {}

Field *FieldSelector::findField(int x, int y)
{
    int tileSize = GameData::read<int>("world", "tileSize");
    int col = y / tileSize + 1;
    int row = x / tileSize + 1;
    int num = ((row -1) * 30) + col;

    Field *foundField = world->getFields()[num -1];
    selectedField = foundField;

    return foundField;
}