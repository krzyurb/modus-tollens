#pragma once

#include "MapMode.h"

class NormalMode : public MapMode {
public:
    sf::Sprite getSprite(Field * field) const override;
};