#pragma once

#include "MapMode.h"

class FertilityMode : public MapMode {
public:
    virtual sf::Sprite getSprite(Field * field) const override;
};
