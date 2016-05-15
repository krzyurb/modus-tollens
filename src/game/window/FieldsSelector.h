#pragma once

#include "Field.h"
#include "World.h"

class World;
class Field;

class FieldSelector {
public:
    FieldSelector(World *world);
    Field *findField(int x, int y);

    bool inRange(int x, int y);

    Field *getSelectedField() {
        return selectedField;
    }

    void setSelectedField(Field *selectedField) {
        this->selectedField = selectedField;
    }

private:
    World *world;
    Field *selectedField;
};