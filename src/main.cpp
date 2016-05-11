#include <SFML/Graphics.hpp>
#include "ModusTollens.h"
#include "GameData.hpp"

int main()
{
    srand(time(nullptr));
    int width  = GameData::read<int>("gameWindow", "width");
    int height = GameData::read<int>("gameWindow", "height");
    std::string title = GameData::read<std::string>("gameWindow", "title");
    sf::RenderWindow window(sf::VideoMode(width , height), title, sf::Style::Titlebar | sf::Style::Close);

    ModusTollens game(window);
    game.loop();

    return 0;
}
