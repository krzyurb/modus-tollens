#pragma once

#include <string>
#include "../World.h"
#include "../Field.h"

class Water : public Field {
private:
    int depth;
    int salinity;

public:
    Water(int x, int y, World * world);

    std::string getDescription();

    void randomize();

    int getDepth() const {
        return depth;
    }

    void setDepth(int depth) {
        this->depth = depth;
    }

    int getSalinity() const {
        return salinity;
    }

    void setSalinity(int salinity) {
        this->salinity = salinity;
    }
};
