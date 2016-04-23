#pragma once

#include <SFML/Graphics.hpp>
#include "World.h"
#include "Field.h"

class Field;
class World;

class Renderer {
private:
    sf::RenderWindow & window;
public:
    Renderer(sf::RenderWindow & window);

    void drawSprite(const sf::Sprite &sprite);

    void drawField(const Field &field);

    void drawWorld(const World &world);
};