#include "Forest.h"
#include "Sawmill.h"
#include <iostream>

void Sawmill::produce() {
    std::string fieldKind = getField()->getKind();

    if(fieldKind == "forest"){
        Forest * field = (Forest *) getField();

        if(field->getTreesCount() > 0){
            int endurance = field->getTree().getEndurance();
            int wood = (endurance / 2) + (std::rand() % ( endurance - (endurance / 2) + 1 ));

            int extraWood = 0;
            for(auto & neighbor: getField()->getNeighbors()) {
                if(neighbor->getKind() == "forest")
                    extraWood++;
            }

            std::cout << "Used: "   << endurance / 10   << " tools";
            std::cout << "Gained: " << wood + extraWood << " wood";
        }
    }
}
