#pragma once

#include "Building.h"

class Farm : public Building {

public:
    Farm(Field *field) : Building(field) {
        this->kind = "farm";
    }

    void produce();
};
