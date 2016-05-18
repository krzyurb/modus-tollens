#pragma once

#include <iostream>
#include "FieldSelector.h"

class NewBuilding {

public:
    NewBuilding(std::string kind, FieldSelector * fieldSelector) : kind(kind), fieldSelector(fieldSelector) {};

    FieldSelector *getFieldSelector() const {
        return fieldSelector;
    }

    const std::string &getKind() const {
        return kind;
    }

private:
    std::string kind;
    FieldSelector * fieldSelector;
};
