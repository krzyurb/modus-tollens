#include "Meadow.h"
#include "Farm.h"

void Farm::produce(Player * player) {
    std::string fieldKind = getField()->getKind();

    if(fieldKind == "meadow"){
        Meadow * field = (Meadow*) getField();
        Soil soil = field->getSoil();
        int fertility = soil.getFertility();
        int food = (fertility / 2) + (std::rand() % ( fertility - (fertility / 2) + 1 ));
        if(player->getStock().tools >= (fertility /10)) {
            player->getStock().food += food / 10;
            player->getStock().tools -= fertility / 10;
        }
    }
}
