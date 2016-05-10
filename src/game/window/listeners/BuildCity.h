#pragma once

#include <game/window/ButtonListener.h>
#include <game/world/Field.h>

class BuildCity : public ButtonListener {
public:
    BuildCity(Field * field);
    void perform();

    Field *getField() const {
        return field;
    }

private:
    Field * field;
};
