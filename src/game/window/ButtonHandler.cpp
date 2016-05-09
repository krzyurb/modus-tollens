#include <GameData.hpp>
#include "ButtonHandler.h"

ButtonHandler::ButtonHandler(FieldSelector * fieldSelector) : fieldSelector(fieldSelector) {}

void ButtonHandler::handleClick(int x, int y) {
    if(inRange(x,y)){
        for(auto &button : getButtons()) {
            if((x > button->getX() && x < button->getX() + 150) && (y > button->getY() && y < button->getY() + 18 )){
                std::cout << fieldSelector->getSelectedField()->getKind() << std::endl;
                button->click();
            }
        }
    }
}

bool ButtonHandler::inRange(int x, int y) {
    int tileSize = GameData::read<int>("world", "tileSize");
    int width    = GameData::read<int>("world", "width")  * tileSize;
    return (x > width);
}

void ButtonHandler::initializeButtons(int x){
    int y = 300;

    Button * buildCity = new Button(x, y, "Build City");
    addButton(buildCity);
}

void ButtonHandler::render(Renderer &renderer) {
    renderer.drawButtons(*this);
}

ButtonHandler::~ButtonHandler() {
    buttons.clear();
}
