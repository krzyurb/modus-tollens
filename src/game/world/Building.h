#pragma once

#include "Field.h"

enum class BuildingKinds { SAWMILL, FARM, QUARRY };

class Player;

class Building {
public:

    Building(Field *field);

    std::string getDescription();

    virtual void produce(Player * player) = 0;

    Field *getField() const {
        return field;
    }

    void setField(Field *field) {
        this->field = field;
    }

    const std::string &getKind() const {
        return kind;
    }

protected:
    Field * field;
    std::string kind;
};
