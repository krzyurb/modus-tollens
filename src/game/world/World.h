#pragma once

#include <vector>

#include "Field.h"
#include "Renderer.h"

class Renderer;
class Field;

class World {
public:
    World();
    ~World();
    void render(Renderer &renderer);

    const std::vector<Field*> &getFields() const {
        return fields;
    }

    void addField(Field * field) {
        fields.push_back(field);
    }

private:
    std::vector<Field*> fields;
};
