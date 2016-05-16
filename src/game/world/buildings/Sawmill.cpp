#include "Forest.h"
#include "Sawmill.h"
#include <iostream>

void Sawmill::produce() {
    std::string fieldKind = getField()->getKind();

    if(fieldKind == "forest"){
        Forest * field = (Forest *) getField();

        if(field->getTreesCount() > 0){
            int endurance = field->getTree().getEndurance() / 10;
            int wood = (endurance / 2) + (std::rand() % ( endurance - (endurance / 2) + 1 ));

            bool deepForest = true;
            for(auto & neighbor: getField()->getNeighbors()) {
                if(neighbor->getKind() != "forest")
                    deepForest = false;
            }

            if(deepForest) { wood += 4; }

            std::cout << "Used: "   << endurance << " tools";
            std::cout << "Gained: " << wood << " wood";
        }
    }
}
