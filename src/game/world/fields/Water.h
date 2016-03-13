#pragma once

#include <string>
#include "World.h"

class Water : public Field {
private:
    int depth;
    int temperature;
    int salinity;

public:
    Water(int x, int y, World *world = nullptr);

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

    int getTemperature() const {
        return temperature;
    }

    void setTemperature(int temperature) {
        this->temperature = temperature;
    }
};
