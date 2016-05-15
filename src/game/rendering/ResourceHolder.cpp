#include "ResourceHolder.h"
#include <boost/filesystem.hpp>
#include <iostream>

using boost::filesystem::path;
using boost::filesystem::directory_iterator;

ResourceHolder::ResourceHolder() {
    boost::filesystem::path resourcesFields("resources/fields");
    std::for_each(directory_iterator(resourcesFields), directory_iterator(), [&](const path & p){
        sf::Texture texture;
        texture.loadFromFile(p.string());
        fields[p.stem().string()] = texture;
    });

    auto loadIcon = [&](const path & p){
        sf::Texture texture;
        texture.loadFromFile(p.string());
        icons[p.stem().string()] = texture;
    };

    path resourcesIcons("resources/icons");
    std::for_each(directory_iterator(resourcesIcons), directory_iterator(), loadIcon);

    path stockIcons("resources/stock");
    std::for_each(directory_iterator(stockIcons), directory_iterator(), loadIcon);

    arial.loadFromFile("resources/arial.ttf");
}

sf::Texture &ResourceHolder::getField(std::string name) {
    return fields[name];
}

sf::Texture &ResourceHolder::getIcon(std::string name) {
    return icons[name];
}

const sf::Font &ResourceHolder::getArial() {
    return arial;
}