#pragma once

#include <string>
#include "../World.h"
#include "../Field.h"

class Water : public Field {
private:
    int depth;
    int temperature;
    int salinity;

public:
    Water(int x, int y, const std::shared_ptr<World>& world);

    std::string getDescription();

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
