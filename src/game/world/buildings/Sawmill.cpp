#include "Forest.h"
#include "Sawmill.h"
#include <iostream>

void Sawmill::produce(Player * player) {
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

            if(player->getStock().tools >= endurance){
                field->cutTrees(wood);
                player->getStock().wood  += wood;
                player->getStock().tools -= endurance;
            } else {
            }
        } else {
            field->setTreesCount(0);
        }
    }
}
