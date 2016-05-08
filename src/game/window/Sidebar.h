#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <game/rendering/Renderer.h>

class Renderer;
class Calendar;

class Sidebar {
public:
    Sidebar(Calendar *calendar);
    void render(Renderer &renderer);

    int getX() const {
        return x;
    }

    Calendar *getCalendar() const {
        return calendar;
    }

private:
    int x;
    Calendar *calendar;
};
