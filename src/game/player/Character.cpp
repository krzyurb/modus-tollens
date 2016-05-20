#include "Character.h"
#include <algorithm>

Character::~Character() { }

void Character::takeField(Field *field) {
    fields.push_back(field);
}

void Character::releaseField(Field *field) {
    fields.erase(std::remove(fields.begin(), fields.end(), field), fields.end());
}
