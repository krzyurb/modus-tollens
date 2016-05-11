#pragma once

#include <SFML/Window/Window.hpp>
#include "World.h"
#include "FieldSelector.h"
#include "GameTimer.h"
#include "Calendar.h"
#include "Renderer.h"
#include "Sidebar.h"

class ModusTollens {
private:
    sf::RenderWindow &window;
    std::unique_ptr<World> world;
    std::unique_ptr<FieldSelector> fieldSelector;
    std::unique_ptr<GameTimer> timer;
    std::unique_ptr<Calendar> calendar;
    std::unique_ptr<Sidebar> sidebar;
    std::unique_ptr<ButtonHandler> buttonHandler;
    Renderer renderer;

public:
    ModusTollens(sf::RenderWindow & window);
    void loop();
};