#pragma once

#include "Field.h"
#include "World.h"

class World;
class Field;

class FieldSelector {
public:
    FieldSelector(World *world);
    Field *findField(int x, int y);

    Field *getSelectedField() const {
        return selectedField;
    }

private:
    World *world;
    Field *selectedField;
};