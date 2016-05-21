#pragma once

#include <iostream>
#include "FieldSelector.h"
#include <game/world/Building.h>

class NewBuilding : public ButtonListener{

public:
    NewBuilding(BuildingKinds kind, FieldSelector * fieldSelector, Player * player) : kind(kind), fieldSelector(fieldSelector), owner(player) {};

    FieldSelector *getFieldSelector() const {
        return fieldSelector;
    }

    const BuildingKinds &getKind() const {
        return kind;
    }

    void perform();

    Player*getOwner() const {
        return owner;
    }

    void setOwner(Player *owner) {
        this->owner = owner;
    }

private:
    BuildingKinds kind;
    FieldSelector * fieldSelector;
    Player * owner;
};
