#include "ResourceHolder.h"
#include <boost/filesystem.hpp>
#include <iostream>

using boost::filesystem::path;
using boost::filesystem::directory_iterator;

ResourceHolder::ResourceHolder() {
    boost::filesystem::path resources("resources/fields");
    std::for_each(directory_iterator(resources), directory_iterator(), [&](const path & p){
        sf::Texture texture;
        texture.loadFromFile(p.string());
        fields[p.stem().string()] = texture;
    });

    arial.loadFromFile("resources/arial.ttf");
}

sf::Texture &ResourceHolder::getField(std::string name) {
    return fields[name];
}

const sf::Font &ResourceHolder::getArial() {
    return arial;
}