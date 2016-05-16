#pragma once

#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

class ResourceHolder {
private:
    std::map<std::string, sf::Texture> fields;
    std::map<std::string, sf::Texture> icons;
    std::map<std::string, sf::Font> fonts;
public:
    ResourceHolder();
    sf::Texture &getField(std::string name);
    sf::Texture &getIcon(std::string name);
    sf::Font &getFont(const std::string & name);
};