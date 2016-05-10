#pragma once

#include <game/window/ButtonListener.h>

class FieldSelector;

class BuildCity : public ButtonListener {
public:
    BuildCity(FieldSelector * fieldSelector);

    void perform();

    FieldSelector *getFieldSelector() const {
        return fieldSelector;
    }

private:
    FieldSelector * fieldSelector;
};
