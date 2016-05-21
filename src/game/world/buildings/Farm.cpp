#include "Meadow.h"
#include "Farm.h"

void Farm::produce(Player * player) {
    std::string fieldKind = getField()->getKind();

    if(fieldKind == "farm"){
        Meadow * field = (Meadow*) getField();
        Soil soil = field->getSoil();
        int fertility = soil.getFertility();
        int food = (fertility / 2) + (std::rand() % ( fertility - (fertility / 2) + 1 ));
        std::cout << "Used: "   << fertility / 10 << " tools";
        std::cout << "Gained: " << food << " food";
    }
}
