#pragma once

#include <SFML/Graphics.hpp>
#include "Field.h"

class Field;

class Renderer {
private:
    sf::RenderWindow & window;
public:
    Renderer(sf::RenderWindow & window);

    void drawSprite(const sf::Sprite &sprite);

    void drawField(const Field &field);
};