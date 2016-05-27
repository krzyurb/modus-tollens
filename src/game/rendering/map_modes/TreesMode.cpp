#include "Forest.h"
#include "TreesMode.h"

TreesMode::TreesMode(sf::Sprite *sprite, Field *field) : MapModeRenderer(sprite, field) {}

void TreesMode::render() {
    sf::Uint8 green = 0;
    sf::Uint8 red   = 0;

    if (field->getKind() == "forest") {
        Forest *forest = (Forest *) field;
        green += forest->getTreesCount() / 4;
        if(forest->getTreesCount() == 0) {
            red = 200;
            green = 0;
        }
    }
    sprite->setColor(sf::Color(red, green, 0));
}
