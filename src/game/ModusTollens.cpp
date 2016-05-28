#include <GameData.hpp>
#include <game/timing/Calendar.h>
#include "WorldGenerator.h"
#include "ModusTollens.h"

ModusTollens::ModusTollens(sf::RenderWindow &window) : window(window), renderer(window) {
    world = WorldGenerator::generate();
    fieldSelector = std::make_unique<FieldSelector>(world.get());
    renderer.setFieldSelector(fieldSelector.get());

    int ticksPerDay = GameData::read<int>("game", "ticksPerDay");
    int tickDuration = GameData::read<int>("game", "tickDuration");

    timer = std::make_unique<GameTimer>(tickDuration);
    calendar = std::make_unique<Calendar>(ticksPerDay);
    timer->addObserver(calendar.get());
    timer->addObserver(&player);

    sidebar = std::make_unique<Sidebar>(calendar.get());
    buttonsBar = std::make_unique<ButtonsBar>(fieldSelector.get(), &player);
    buttonsBar->initializeButtons(sidebar->getX());
}

void ModusTollens::loop() {
    timer->start();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed){
                fieldSelector->findField(event.mouseButton.x, event.mouseButton.y);
                buttonsBar->handleClick(event.mouseButton.x, event.mouseButton.y);
            }
            if(event.type == sf::Event::KeyPressed){
                renderer.setMapMode(event.text.unicode);
            }
        }

        window.clear(sf::Color::Black);

        world->render(renderer);
        buttonsBar->render(renderer);
        sidebar->render(renderer);
        player.render(renderer);

        window.display();
    }
}
