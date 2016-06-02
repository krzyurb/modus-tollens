#include <SFML/Graphics/Sprite.hpp>
#include <game/world/fields/Meadow.h>
#include "BuildingMode.h"

sf::Sprite BuildingMode::getSprite(Field * field) const {
    sf::Uint8 green = 0;
    sf::Uint8 red   = 0;
    sf::Sprite sprite;

    if(!field->getBuildings().empty()) {
        red = 255;
        green = 165;
    }

    if(field->getKind() == "city") {
        red = 200;
    }

    sprite.setColor(sf::Color(red, green, 0));
    return sprite;
}