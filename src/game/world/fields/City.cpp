#include "City.h"

City::City(int x, int y, World * world) : Field(x, y, world) {
        this->kind = "city";
}



