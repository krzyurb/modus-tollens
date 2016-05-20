#pragma once

#include <vector>

class Field;

class Character {
private:
    std::vector<Field*> fields;
public:
    virtual ~Character() = 0;
    void takeField(Field *field);
};
