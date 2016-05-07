#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <game/rendering/Renderer.h>

class Renderer;

class Sidebar {
public:
    Sidebar();
    void render(Renderer &renderer);

    int getX() const {
        return x;
    }

private:
    int x;
};
