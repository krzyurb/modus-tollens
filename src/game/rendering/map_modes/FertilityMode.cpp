#include "Meadow.h"
#include "FertilityMode.h"

FertilityMode::FertilityMode(sf::Sprite * sprite, Field *field) : MapModeRenderer(sprite, field) {}

void FertilityMode::render() {
    sf::Uint8 green = 0;
    sf::Uint8 red   = 0;

    if (field->getKind() == "meadow") {
        Meadow *meadow = (Meadow *) field;
        if (meadow->getSoil().getName() != "") {
            green += meadow->getSoil().getFertility() * 2;
        } else {
            red = 200;
        }
    }
    sprite->setColor(sf::Color(red, green, 0));
}

