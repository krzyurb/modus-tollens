#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include "Field.h"

class MapModeRenderer{
public:
    MapModeRenderer(sf::Sprite * sprite, Field * field): sprite(sprite), field(field) {}

    virtual void render() = 0;

protected:
    sf::Sprite * sprite;
    Field * field;
};