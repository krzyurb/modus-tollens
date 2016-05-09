#include <iostream>
#include <game/timing/Calendar.h>
#include "Field.h"
#include "World.h"

Renderer::Renderer(sf::RenderWindow & window):window(window) {}

void Renderer::drawSprite(const sf::Sprite &sprite) {
    window.draw(sprite);
}

void Renderer::drawField(const Field &field, bool dark){
    sf::Texture texture;
    sf::Sprite  sprite;

    sprite.setTexture(resourceHolder.getField(field.getKind()));
    sprite.setPosition(field.getX(), field.getY());

    if(dark){
        sf::Uint8 dark = 180;
        sprite.setColor(sf::Color(dark, dark, dark));
    }

    window.draw(sprite);
}

void Renderer::drawWorld(const World &world){
    Field *selectedField = fieldSelector->getSelectedField();

    for(auto &field : world.getFields()) {
        field->render(*this);
        selectedField->render(*this, true);
    }
}

void Renderer::drawSidebar(const Sidebar &sidebar){
    Field *selectedField = fieldSelector->getSelectedField();

    sf::Sprite  sprite;
    sf::Sprite  calendarSprite;
    sf::Text fieldPosition;
    sf::Text calendar;

    sprite.setTexture(resourceHolder.getField(selectedField->getKind() + "_preview"));

    fieldPosition.setString(sf::String(*selectedField));
    fieldPosition.setFont(resourceHolder.getArial());
    fieldPosition.setCharacterSize(18);
    fieldPosition.setColor(sf::Color::White);
    fieldPosition.setPosition(sidebar.getX(), 60);

    calendar.setString(sf::String(*sidebar.getCalendar()));
    calendar.setFont(resourceHolder.getArial());
    calendar.setCharacterSize(18);
    calendar.setColor(sf::Color::White);
    calendar.setPosition(sidebar.getX() + 40, 10);
    calendarSprite.setPosition(sidebar.getX(), 15);

    sprite.setPosition(sidebar.getX(), 100);

    window.draw(sprite);
    window.draw(fieldPosition);
    window.draw(calendar);
    window.draw(calendarSprite);
}

void Renderer::setFieldSelector(FieldSelector * fieldSelector) {
    this->fieldSelector = fieldSelector;
}
