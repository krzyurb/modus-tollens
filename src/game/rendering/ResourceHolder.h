#pragma once

#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

class ResourceHolder {
private:
    std::map<std::string, sf::Texture> fields;
    std::map<std::string, sf::Texture> icons;
    sf::Font arial;
public:
    ResourceHolder();
    sf::Texture &getField(std::string name);
    sf::Texture &getIcon(std::string name);
    const sf::Font &getArial();
};