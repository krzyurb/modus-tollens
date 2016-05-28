#pragma once

#include "MapMode.h"

class TreesMode : public MapMode {
public:
    virtual sf::Sprite getSprite(Field * field) const override;
};
