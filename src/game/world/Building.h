#pragma once

#include "Field.h"

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

    void produce() {}

protected:
    Field * field;
    std::string kind;
};
