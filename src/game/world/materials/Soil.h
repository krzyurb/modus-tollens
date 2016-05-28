#pragma once

#include <string>
#include <stdlib.h>
#include <iostream>

static const char * soilKinds[] = { "", "chernozem", "brown", "podzol", "peat" };

class Soil {
private:
    std::string name;
    int fertility;

public:
    Soil();
    Soil(std::string name);

    static std::string randomizeSoilKind();

    int getFertility() const {
        return fertility;
    }

    void setFertility(int fertility) {
        this->fertility = fertility;
    }

    const std::string& getName() const {
        return name;
    }

    void setName(const std::string& name) {
        this->name = name;
    }
};
