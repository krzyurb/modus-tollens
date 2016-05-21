#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Sidebar.h"
#include "Button.h"
#include "ButtonHandler.h"
#include "FieldSelector.h"
#include "World.h"
#include "Field.h"
#include "ResourceHolder.h"

class Player;
class Field;
class World;
class Sidebar;
class FieldSelector;
class ButtonHandler;
class Button;

enum class MapMode { NORMAL, FERTILITY, TREES, SIZE };

class Renderer {
private:
    ResourceHolder resourceHolder;
    sf::RenderWindow & window;
    FieldSelector * fieldSelector;
    sf::Font &textFont;
    MapMode mapMode;

public:
    Renderer(sf::RenderWindow & window);

    void drawSprite(const sf::Sprite &sprite);

    void drawField(Field *field, bool dark = false);

    void drawWorld(World &world);
    void drawSidebar(const Sidebar &sidebar);
    void drawButtons(const ButtonHandler &buttonHandler);
    void drawButton(const Button &button);
    void drawPlayer(const Player &player);
    void setFieldSelector(FieldSelector * fieldSelector);

    void setMapMode(int unicode);

    MapMode getMapMode() const {
        return mapMode;
    }

    FieldSelector *getFieldSelector() const {
        return fieldSelector;
    }
};
