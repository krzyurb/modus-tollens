#include <iostream>
#include "Field.h"
#include "World.h"

Renderer::Renderer(sf::RenderWindow & window):window(window) {}

void Renderer::drawSprite(const sf::Sprite &sprite) {
    window.draw(sprite);
}

void Renderer::drawField(const Field &field){
    sf::Texture texture;
    sf::Sprite  sprite;

    if (!texture.loadFromFile("resources/fields/" + field.getKind() + ".png"))
    {
        std::cout << "No texture found" << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(field.getX(), field.getY());
    window.draw(sprite);
}

void Renderer::drawWorld(const World &world){
    for( size_t i = 0; i < world.getFields().size(); i++ )
        world.getFields()[i].render(*this);
}