#pragma once

#include <iostream>
#include "FieldSelector.h"
#include <game/world/Building.h>

class NewBuilding : public ButtonListener{

public:
    NewBuilding(BuildingKinds kind, FieldSelector * fieldSelector) : kind(kind), fieldSelector(fieldSelector) {};

    FieldSelector *getFieldSelector() const {
        return fieldSelector;
    }

    const BuildingKinds &getKind() const {
        return kind;
    }

    void perform();

private:
    BuildingKinds kind;
    FieldSelector * fieldSelector;
};
