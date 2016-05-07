#pragma once

#include <SFML/Graphics.hpp>
#include <game/window/Sidebar.h>
#include "game/window/FieldsSelector.h"
#include "World.h"
#include "Field.h"

class Field;
class World;
class Sidebar;
class FieldSelector;

class Renderer {
private:
    sf::RenderWindow & window;
    FieldSelector * fieldSelector;

public:
    Renderer(sf::RenderWindow & window);

    void drawSprite(const sf::Sprite &sprite);

    void drawField(const Field &field, bool dark);

    void drawWorld(const World &world);

    void drawSidebar(const Sidebar &sidebar);

    void setFieldSelector(FieldSelector * fieldSelector);
};