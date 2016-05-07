#include <iostream>
#include "Field.h"
#include "World.h"

Renderer::Renderer(sf::RenderWindow & window):window(window) {}

void Renderer::drawSprite(const sf::Sprite &sprite) {
    window.draw(sprite);
}

void Renderer::drawField(const Field &field, bool dark){
    sf::Texture texture;
    sf::Sprite  sprite;

    if (!texture.loadFromFile("resources/fields/" + field.getKind() + ".png"))
    {
        std::cout << "No texture found" << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(field.getX(), field.getY());

    if(dark){
        sf::Uint8 dark = 180;
        sprite.setColor(sf::Color(dark, dark, dark));
    }

    window.draw(sprite);
}

void Renderer::drawWorld(const World &world){
    Field *selectedField = fieldSelector->getSelectedField();

    for(auto field : world.getFields()) {
        field->render(*this, false);
        if(selectedField != nullptr) {
            selectedField->render(*this, true);
        }
    }
}

void Renderer::drawSidebar(const Sidebar &sidebar){
    Field *selectedField = fieldSelector->getSelectedField();

    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("resources/arial.ttf")) {
        std::cout << "No font found" << std::endl;
    }

    if(selectedField != nullptr) {
        text.setString(sf::String(*selectedField));
    }

    text.setFont(font);
    text.setCharacterSize(18);
    text.setColor(sf::Color::White);
    text.setPosition(sidebar.getX(), 10);
    window.draw(text);
}

void Renderer::setFieldSelector(FieldSelector * fieldSelector) {
    this->fieldSelector = fieldSelector;
}