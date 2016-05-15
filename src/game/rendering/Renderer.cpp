#include <iostream>
#include <GameData.hpp>
#include "Player.h"
#include "Calendar.h"
#include "ButtonHandler.h"
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

void Renderer::drawWorld(World &world){
    Field *selectedField = fieldSelector->getSelectedField();

    for(auto field : world.getFields()) {
        field->render(*this);
        selectedField->render(*this, true);
    }
}

void Renderer::drawSidebar(const Sidebar &sidebar){
    Field *selectedField = fieldSelector->getSelectedField();

    sf::Sprite  fieldPreview;
    sf::Sprite  fieldIcon;
    sf::Sprite  calendarSprite;
    sf::Text    fieldPosition;
    sf::Text    calendar;
    sf::Text    fieldDesc;

    fieldPreview.setTexture(resourceHolder.getField(selectedField->getKind() + "_preview"));
    fieldIcon.setTexture(resourceHolder.getField(selectedField->getKind()));

    fieldPosition.setString(sf::String(*selectedField));
    fieldPosition.setFont(resourceHolder.getArial());
    fieldPosition.setCharacterSize(18);
    fieldPosition.setColor(sf::Color::White);
    fieldPosition.setPosition(sidebar.getX() + 20, 60);
    fieldIcon.setPosition(sidebar.getX(), 64);

    calendar.setString(sf::String(*sidebar.getCalendar()));
    calendar.setFont(resourceHolder.getArial());
    calendar.setCharacterSize(18);
    calendar.setColor(sf::Color::White);
    calendar.setPosition(sidebar.getX() + 40, 10);
    calendarSprite.setPosition(sidebar.getX(), 15);
    calendarSprite.setTexture(resourceHolder.getIcon("calendar"));
    fieldPreview.setPosition(sidebar.getX(), 100);

    fieldDesc.setString(selectedField->getDescription());
    fieldDesc.setFont(resourceHolder.getArial());
    fieldDesc.setCharacterSize(18);
    fieldDesc.setColor(sf::Color::White);
    fieldDesc.setPosition(sidebar.getX(), 200);

    window.draw(fieldPreview);
    window.draw(fieldIcon);
    window.draw(fieldPosition);
    window.draw(fieldDesc);
    window.draw(calendar);
    window.draw(calendarSprite);
}

void Renderer::drawButtons(const ButtonHandler &buttonHandler){
    for(auto &button: buttonHandler.getButtons()) {
        button->render(*this);
    }
}

void Renderer::drawButton(const Button &button) {
    sf::Text text;
    text.setString(button.getName());
    text.setFont(resourceHolder.getArial());
    text.setCharacterSize(18);
    text.setColor(sf::Color::Green);
    text.setPosition(button.getX(), button.getY());
    window.draw(text);
}

void Renderer::drawPlayer(const Player &player) {
    const Stock &stock = player.getStock();

    int worldHeight = GameData::read<int>("world", "height");
    int tileSize = GameData::read<int>("world", "tileSize");
    int bottomBar = worldHeight * tileSize + 5;

    std::stringstream ss;

    sf::Sprite wood(resourceHolder.getIcon("wood"));
    wood.setPosition(10, bottomBar);
    wood.scale(sf::Vector2f(0.3f, 0.3f));

    ss << std::setprecision(2) << stock.wood;
    sf::Text woodAmount;
    woodAmount.setString(ss.str());
    woodAmount.setPosition(20 + wood.getGlobalBounds().width, bottomBar);
    woodAmount.setFont(resourceHolder.getArial());
    woodAmount.setColor(sf::Color::White);

    window.draw(wood);
    window.draw(woodAmount);
}

void Renderer::setFieldSelector(FieldSelector * fieldSelector) {
    this->fieldSelector = fieldSelector;
}
