#include <game/world/fields/City.h>
#include "NewBuilding.h"

void NewBuilding::perform() {
    Field * field = getFieldSelector()->getSelectedField();

    switch(getKind()){
        case BuildingKinds::SAWMILL:
            std::cout << "Builded sawmill!";
        break;

        case BuildingKinds::FARM:
            std::cout << "Builded farm!";
        break;
    }
}
