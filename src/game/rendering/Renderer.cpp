#include <iostream>
#include <GameData.hpp>
#include <game/rendering/map_modes/FertilityMode.h>
#include <game/rendering/map_modes/TreesMode.h>
#include "Player.h"
#include "Meadow.h"
#include "Forest.h"
#include "Calendar.h"

Renderer::Renderer(sf::RenderWindow & window)
    :window(window), textFont(resourceHolder.getFont("arial")) {
    mapMode = MapMode::NORMAL;
}

void Renderer::drawSprite(const sf::Sprite &sprite) {
    window.draw(sprite);
}

void Renderer::drawField(Field *field, bool dark){
    sf::Texture texture;
    sf::Sprite  sprite;

    sprite.setTexture(resourceHolder.getField(field->getKind()));
    sprite.setPosition(field->getX(), field->getY());

    if(getMapMode() != MapMode::NORMAL){
        drawMapMode(&sprite, field);
    }

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
    fieldPosition.setFont(textFont);
    fieldPosition.setCharacterSize(18);
    fieldPosition.setColor(sf::Color::White);
    fieldPosition.setPosition(sidebar.getX() + 20, 60);
    fieldIcon.setPosition(sidebar.getX(), 64);

    calendar.setString(sf::String(*sidebar.getCalendar()));
    calendar.setFont(textFont);
    calendar.setCharacterSize(18);
    calendar.setColor(sf::Color::White);
    calendar.setPosition(sidebar.getX() + 40, 10);
    calendarSprite.setPosition(sidebar.getX(), 15);
    calendarSprite.setTexture(resourceHolder.getIcon("calendar"));
    fieldPreview.setPosition(sidebar.getX(), 100);

    fieldDesc.setString(selectedField->getDescription());
    fieldDesc.setFont(textFont);
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
    text.setFont(textFont);
    text.setCharacterSize(18);
    text.setColor(sf::Color::Green);
    text.setPosition(button.getX(), button.getY());
    window.draw(text);
}

void Renderer::drawPlayer(Player &player) {
    Stock &stock = player.getStock();

    int worldHeight = GameData::read<int>("world", "height");
    int worldWidth = GameData::read<int>("world", "width");
    int tileSize = GameData::read<int>("world", "tileSize");
    int bottomBar = worldHeight * tileSize + 5;
    size_t stockWidth = worldWidth * tileSize / 4;
    const size_t padding = 10;

    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    sf::Sprite icon;
    icon.setPosition(padding, bottomBar);
    icon.scale(sf::Vector2f(0.3f, 0.3f));
    sf::Text amount;
    amount.setFont(textFont);

    const std::string stockNames[] = {"wood", "stone", "tools", "food"};
    std::vector<double> v { stock.wood, stock.stone, stock.tools, stock.food };

    for(size_t i = 0; i < 4; ++i) {
        icon.setTexture(resourceHolder.getIcon(stockNames[i]));
        icon.setPosition(stockWidth*i + padding, bottomBar);
        size_t iconWidth = icon.getGlobalBounds().width;

        ss.str(std::string());
        ss.clear();
        ss << v[i] << '\n';
        amount.setString(ss.str());
        amount.setPosition(stockWidth*i + iconWidth + padding*2, bottomBar);

        window.draw(icon);
        window.draw(amount);
    }
}

void Renderer::setFieldSelector(FieldSelector * fieldSelector) {
    this->fieldSelector = fieldSelector;
}

void Renderer::setMapMode(int unicode) {
    if(unicode >= sf::Keyboard::Num1 && unicode < (int)MapMode::SIZE + sf::Keyboard::Num1)
        this->mapMode = (MapMode)(unicode - sf::Keyboard::Num1);
}

void Renderer::drawMapMode(sf::Sprite *sprite, Field *field) {
    switch(getMapMode()){
        case MapMode::FERTILITY: {
            FertilityMode(sprite, field).render();
            break;
        }

        case MapMode::TREES: {
            TreesMode(sprite, field).render();
            break;
        }
    }
}
