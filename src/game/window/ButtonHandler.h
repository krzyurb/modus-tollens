#pragma once

#include "Button.h"

class ButtonHandler {
private:
    std::vector<Button*> buttons;

public:

    void handleClick(int x, int y);

    bool inRange(int x, int y);

    void addButton(Button * button) {
        buttons.push_back(button);
    }

    const std::vector<Button *> &getButtons() const {
        return buttons;
    }
};
