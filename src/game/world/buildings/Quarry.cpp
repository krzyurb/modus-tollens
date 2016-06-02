#include "Quarry.h"
#include "Mountains.h"

void Quarry::produce(Player * player) {
    if(getField()->getKind() == "mountains"){
        Mountains * field = dynamic_cast<Mountains *>(getField());
        if(field == nullptr || field->getStoneCount() <= 0) return;
        if(field->getStoneCount() < 0) field->setStoneCount(0);

        if(player->getStock().tools >= 1){
            field->mineStone(5);
            player->getStock().stone += 5;
            player->getStock().tools -= 1;
        }
    }
}
