#pragma once

#include <SFML/Graphics.hpp>
#include <game/window/Sidebar.h>
#include <game/window/Button.h>
#include <game/window/ButtonHandler.h>
#include "FieldsSelector.h"
#include "World.h"
#include "Field.h"
#include "ResourceHolder.h"

class Field;
class World;
class Sidebar;
class FieldSelector;
class ButtonHandler;
class Button;

class Renderer {
private:
    ResourceHolder resourceHolder;
    sf::RenderWindow & window;
    FieldSelector * fieldSelector;

public:
    Renderer(sf::RenderWindow & window);

    void drawSprite(const sf::Sprite &sprite);

    void drawField(const Field &field, bool dark = false);

    void drawWorld(World &world);

    void drawSidebar(const Sidebar &sidebar);

    void drawButtons(const ButtonHandler &buttonHandler);

    void drawButton(const Button &button);

    void setFieldSelector(FieldSelector * fieldSelector);


    FieldSelector *getFieldSelector() const {
        return fieldSelector;
    }
};