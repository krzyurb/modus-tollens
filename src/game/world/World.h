#pragma once

#include <vector>

#include "Field.h"
#include "Renderer.h"

class Renderer;
class Field;

class World {
public:
    void render(Renderer &renderer);

    const std::vector<std::unique_ptr<Field>> &getFields() {
        return fields;
    }

    void addField(std::unique_ptr<Field> &&field) {
        fields.push_back(std::move(field));
    }

    void setField(int id, Field * field){
        fields[id].reset(field);
    }

    Field* operator[](size_t id) {
        return fields[id].get();
    }

    const Field* operator[](size_t id) const {
        return fields[id].get();
    }

    Field* get(size_t id) {
        return (*this)[id];
    }

private:
    std::vector<std::unique_ptr<Field>> fields;
};
