#include "Water.h"

Water::Water(int x, int y, World *world = nullptr) : Field(x,y, world) {
    this->kind = "Water";
}
