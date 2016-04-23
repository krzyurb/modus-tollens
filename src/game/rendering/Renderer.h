#pragma once

#include <SFML/Graphics.hpp>

class Renderer {
private:
    sf::RenderWindow & window;
public:
    Renderer(sf::RenderWindow & window);
};