#pragma once

#include <vector>
#include "Field.h"

class Field;

class World {
public:
    World();
    ~World();
private:
    std::vector <Field> fields;
};
