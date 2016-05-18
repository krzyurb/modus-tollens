#pragma once

#include "Field.h"

enum class BuildingKinds { SAWMILL, FARM };

class Building {
public:

    Building(Field *field) : field(field) {}

    Field *getField() const {
        return field;
    }

    void setField(Field *field) {
        Building::field = field;
    }

    const std::string &getKind() const {
        return kind;
    }

    virtual void produce() {}

protected:
    Field * field;
    std::string kind;
};
