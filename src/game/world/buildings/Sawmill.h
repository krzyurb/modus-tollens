#pragma once

#include "Building.h"

class Sawmill : public Building {

public:
    Sawmill(Field *field) : Building(field) {
        this->kind = "sawmill";
    }

    void produce();
};
