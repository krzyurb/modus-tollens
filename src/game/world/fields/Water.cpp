#include "Water.h"

Water::Water(int x, int y, const std::shared_ptr<World>& world) : Field(x,y, world) {
    this->kind = "Water";
}
