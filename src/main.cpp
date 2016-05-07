#include <SFML/Graphics.hpp>
#include <game/window/FieldsSelector.h>
#include <game/window/Sidebar.h>

#include "WorldGenerator.h"
#include "GameData.hpp"
#include "GameTimer.h"
#include "Calendar.h"

int main()
{
    srand(time(nullptr));
    // create the window
    int width  = GameData::read<int>("gameWindow", "width");
    int height = GameData::read<int>("gameWindow", "height");
    std::string title = GameData::read<std::string>("gameWindow", "title");
    sf::RenderWindow window(sf::VideoMode(width , height), title, sf::Style::Titlebar | sf::Style::Close);

    Renderer renderer(window);
    World world = WorldGenerator::generate();
    FieldSelector fieldSelector(&world);
    renderer.setFieldSelector(&fieldSelector);
    
    Sidebar sidebar;

    int ticksPerDay = GameData::read<int>("game", "ticksPerDay");
    int tickDuration = GameData::read<int>("game", "tickDuration");

    GameTimer timer(tickDuration);
    Calendar calendar(ticksPerDay);
    timer.addObserver(&calendar);
    timer.start();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed){
                fieldSelector.findField(event.mouseButton.x, event.mouseButton.y);
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // render whole world
        world.render(renderer);

        // render sidebar
        sidebar.render(renderer);

        window.display();
    }
    return 0;
}