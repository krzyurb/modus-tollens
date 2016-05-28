#include "Building.h"
#include <sstream>

Building::Building(Field * field) : field(field) {}

std::string Building::getDescription() {
    return getKind();
}