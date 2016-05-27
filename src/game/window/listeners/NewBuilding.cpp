#include "City.h"
#include "Sawmill.h"
#include "Farm.h"
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
    field->takeOwnership((Character *) getOwner());
    field->addBuilding(building);
}
