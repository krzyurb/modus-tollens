#include <GameData.hpp>
#include "NewBuilding.h"
#include "BuildCity.h"

ButtonsBar::ButtonsBar(FieldSelector * fieldSelector, Player * currentPlayer) : fieldSelector(fieldSelector), currentPlayer(currentPlayer) {}

void ButtonsBar::handleClick(int x, int y) {
    if(inRange(x,y)){
        for(auto &button : getButtons()) {
            if((x > button->getX() && x < button->getX() + 150) && (y > button->getY() && y < button->getY() + 18 )){
                button->click();
            }
        }
    }
}

bool ButtonsBar::inRange(int x, int y) {
    int tileSize = GameData::read<int>("world", "tileSize");
    int width    = GameData::read<int>("world", "width")  * tileSize;
    return (x > width);
}

void ButtonsBar::initializeButtons(int x){
    int y = 400;

    std::unique_ptr<Button> buildCity = std::make_unique<Button>(x, y, "Build City");
    BuildCity * buildCityListener = new BuildCity(fieldSelector, getCurrentPlayer());
    buildCity->setListener(buildCityListener);
    y+=25;
    std::unique_ptr<Button> newSawmill  = std::make_unique<Button>(x, y, "Build Sawmill");
    NewBuilding * newSawmillListener  = new NewBuilding(BuildingKinds::SAWMILL, fieldSelector, getCurrentPlayer());
    newSawmill->setListener(newSawmillListener);

    y+=25;
    std::unique_ptr<Button> newFarm  = std::make_unique<Button>(x, y, "Build Farm");
    NewBuilding * newFarmListener  = new NewBuilding(BuildingKinds::FARM, fieldSelector, getCurrentPlayer());
    newFarm->setListener(newFarmListener);

    addButton(std::move(buildCity));
    addButton(std::move(newSawmill));
    addButton(std::move(newFarm));
}

void ButtonsBar::render(Renderer &renderer) {
    renderer.drawButtons(*this);
}

ButtonsBar::~ButtonsBar() {
    buttons.clear();
}
