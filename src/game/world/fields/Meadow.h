#pragma once

#include <string>
#include "World.h"
#include "Field.h"
#include "Soil.h"

class Meadow : public Field {
private:
    Soil soil;

public:
    Meadow(int x, int y, World * world);

    Soil& getSoil() { return soil; }

    void setSoil(const std::string name);

    std::string getDescription();

    void randomize();
};

