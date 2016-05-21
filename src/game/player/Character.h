#pragma once

#include <vector>

class Field;

class Character {
public:
    std::vector<Field*> fields;
    virtual ~Character() = 0;
    void takeField(Field *field);
    void releaseField(Field *field);

    const std::vector<Field *> &getFields() const {
        return fields;
    }
};
