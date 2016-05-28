#include "Soil.h"
#include <string>
#include <stdlib.h>

Soil::Soil() {}

Soil::Soil(std::string name) : name(name) {}

std::string Soil::randomizeSoilKind() {
    int size = sizeof(soilKinds) / 8;
    return soilKinds[rand() % size];
}
