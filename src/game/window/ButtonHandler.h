#pragma once

#include "Button.h"

class Button;
class FieldSelector;

class ButtonHandler {
private:
    std::vector<Button*> buttons;
    FieldSelector * fieldSelector;
public:

    ButtonHandler(FieldSelector * fieldSelector);

    ~ButtonHandler();

    void handleClick(int x, int y);

    bool inRange(int x, int y);

    void initializeButtons(int x);

    void render(Renderer &renderer);

    FieldSelector *getFieldSelector() const {
        return fieldSelector;
    }

    void addButton(Button * button) {
        buttons.push_back(button);
    }

    const std::vector<Button *> &getButtons() const {
        return buttons;
    }

};
