#pragma once

#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

class ResourceHolder {
private:
    std::map<std::string, sf::Texture> fields;
    sf::Font arial;
public:
    ResourceHolder();
    sf::Texture &getField(std::string name);
    const sf::Font &getArial();
};