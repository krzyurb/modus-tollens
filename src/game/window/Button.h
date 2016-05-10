#pragma once
#include <string>
#include <game/rendering/Renderer.h>
#include "ButtonListener.h"

class Renderer;

class Button {
private:
    int x,y;
    std::string name;
    ButtonListener * listener;

public:

    Button(int x, int y, std::string name);

    void click();

    void render(Renderer &renderer, bool dark = false)const;

    const ButtonListener *getListener() const {
        return listener;
    }

    void setListener(ButtonListener * listener) {
        Button::listener = listener;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Button::name = name;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Button::y = y;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        Button::x = x;
    }
};
