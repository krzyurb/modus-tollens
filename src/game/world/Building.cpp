#include "Building.h"
#include <iostream>
#include <sstream>

std::string Building::getDescription() {
    std::stringstream result;
    result << getKind() << " ";
    return result.str();
}
