#include <iostream>
#include <sstream>
#include <GameData.hpp>
#include "Field.h"

Field::Field(int x, int y, World * world) : x(x), y(y), world(world) {}

Field::~Field() {}

void Field::render(Renderer &renderer, bool dark)const {
    renderer.drawField(*this, dark);
}

Field::operator std::string() {
    std::stringstream result;
    result << "(" << x << ", " << y << ") " << kind;
    return result.str();
}

std::string Field::getDescription() {
    return "No info";
}

void Field::randomize() {}

std::vector<Field*> Field::getNeighbors(){
    int width  = GameData::read<int>("world", "width");
    int height = GameData::read<int>("world", "height");
    std::vector<Field*> neighbors;
    if(getId() > 0)
        neighbors.push_back(getWorld()->getFields()[getId() - 1]);
    if(getId() < getWorld()->getFields().size())
        neighbors.push_back(getWorld()->getFields()[getId() + 1]);
    if(getId() >= height)
        neighbors.push_back(getWorld()->getFields()[getId() - height]);
    if(getId() < height * (width - 1))
        neighbors.push_back(getWorld()->getFields()[getId() + height]);
    return neighbors;
}
