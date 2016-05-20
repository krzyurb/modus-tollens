#include "Character.h"

Character::~Character() { }

void Character::takeField(Field *field) {
    fields.push_back(field);
}
