#include "Forest.h"
#include "Sawmill.h"

void Sawmill::produce(Player * player) {
    if(getField()->getKind() == "forest"){
        Forest * field = dynamic_cast<Forest *>(getField());
        if(field == nullptr || field->getTreesCount() <= 0) return;
        if(field->getTreesCount() < 0) field->setTreesCount(0);

        int endurance = field->getTree().getEndurance() / 10;
        int wood = (endurance / 2) + (std::rand() % ( endurance - (endurance / 2) + 1 ));
        int extraWood = 0;
        bool deepForest = true;

        for(auto & neighbor: getField()->getNeighbors()) {
            if (neighbor->getKind() != "forest") deepForest = false;
        }
        if(deepForest) extraWood+= 4;

        if(player->getStock().tools >= endurance){
            field->cutTrees(wood);
            player->getStock().wood  += (wood + extraWood);
            player->getStock().tools -= endurance;
        }
    }
}
