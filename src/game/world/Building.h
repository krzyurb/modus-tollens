#pragma once

#include "Field.h"

enum class BuildingKinds { SAWMILL, FARM };

class Player;

class Building {
public:

    Building(Field *field) : field(field) {}

    std::string getDescription();

    Field *getField() const {
        return field;
    }

    void setField(Field *field) {
        Building::field = field;
    }

    const std::string &getKind() const {
        return kind;
    }

    virtual void produce(Player * player) = 0;

protected:
    Field * field;
    std::string kind;
};
