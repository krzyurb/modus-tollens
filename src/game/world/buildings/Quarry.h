#pragma once

#include "Building.h"

class Quarry : public Building {
public:
    Quarry(Field *field) : Building(field) {
        this->kind = "quarry";
    }

    void produce(Player * player);
};
