#include <game/world/fields/City.h>
#include <game/world/buildings/Sawmill.h>
#include <game/world/buildings/Farm.h>
#include "NewBuilding.h"

void NewBuilding::perform() {
    Field * field = getFieldSelector()->getSelectedField();
    Building * building;
    switch(getKind()){
        case BuildingKinds::SAWMILL:
            building = new Sawmill(field);
        break;

        case BuildingKinds::FARM:
            building = new Farm(field);
        break;
    }

    field->addBuilding(building);
}
