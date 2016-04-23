#pragma once

#include <vector>

#include "Field.h"
#include "Renderer.h"

class Field;

class World {
public:
    World();
    ~World();
    void render(Renderer &renderer);

    const std::vector<Field> &getFields() const {
        return fields;
    }

private:
    std::vector <Field> fields;
};
