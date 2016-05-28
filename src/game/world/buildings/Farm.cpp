#include "Meadow.h"
#include "Farm.h"

void Farm::produce(Player * player) {
    if(getField()->getKind() == "meadow"){
        Meadow * field = dynamic_cast<Meadow*>(getField());
        Soil   * soil  = dynamic_cast<Soil*>(&field->getSoil());
        if(field == nullptr || soil == nullptr) return;

        int fertility = soil->getFertility();
        int food = (fertility / 2) + (std::rand() % ( fertility - (fertility / 2) + 1 ));

        if(player->getStock().tools >= (fertility /10)) {
            player->getStock().food  += food / 10;
            player->getStock().tools -= fertility / 10;
        }
    }
}
