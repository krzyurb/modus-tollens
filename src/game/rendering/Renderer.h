#pragma once

#include <SFML/Graphics.hpp>

class Renderer {
private:
    sf::RenderWindow & window;
public:
    Renderer(sf::RenderWindow & window);

    void drawSprite(const sf::Sprite &sprite);
};