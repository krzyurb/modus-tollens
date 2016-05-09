#pragma once

#include <string>

enum class SoilKind{
    BROWN, SIZE
};

class Soil {
private:
    std::string name;
    int fertility;

public:
    Soil();
    Soil(std::string name);

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