#pragma once

#include <SFML/Graphics.hpp>
#include <game/rendering/map_modes/MapMode.h>
#include "MapMode.h"
#include "Player.h"
#include "Sidebar.h"
#include "Button.h"
#include "ButtonsBar.h"
#include "FieldSelector.h"
#include "World.h"
#include "Field.h"
#include "ResourceHolder.h"

class Player;
class Field;
class World;
class Sidebar;
class FieldSelector;
class ButtonsBar;
class Button;

class Renderer {
private:
    ResourceHolder resourceHolder;
    sf::RenderWindow & window;
    FieldSelector * fieldSelector;
    sf::Font &textFont;
    const MapMode * mapMode;

public:
    Renderer(sf::RenderWindow & window);

    void drawSprite(const sf::Sprite &sprite);

    void drawField(Field *field, bool dark = false);

    void drawWorld(World &world);
    void drawSidebar(const Sidebar &sidebar);
    void drawButtons(const ButtonsBar &buttonsBar);
    void drawButton(const Button &button);
    void drawPlayer(Player &player);
    void setFieldSelector(FieldSelector * fieldSelector);

    void setMapMode(int unicode);

    FieldSelector *getFieldSelector() const {
        return fieldSelector;
    }
};
