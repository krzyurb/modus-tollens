#include <SFML/Graphics.hpp>
#include "Meadow.h"
#include "Water.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Modus tollens",
                            sf::Style::Fullscreen | sf::Style::Titlebar | sf::Style::Close);


    Renderer renderer(window);
    Field *meadow = new Meadow(0, 0, nullptr);
    Field *water  = new Water(0, 16, nullptr);

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
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        renderer.drawField(*meadow);
        renderer.drawField(*water);

        window.display();
    }
    return 0;
}