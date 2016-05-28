#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <memory>
#include <iostream>

class Field;

class MapMode {
private:
    static std::vector<std::unique_ptr<MapMode>> modes;
public:
    static void init();
    static const MapMode * get(size_t n) {
        return modes[n].get();
    }

    virtual sf::Sprite getSprite(Field * field) const = 0;

    enum { NORMAL, FERTILITY, TREES, SIZE };
};