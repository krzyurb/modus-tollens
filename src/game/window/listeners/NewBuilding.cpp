#include "City.h"
#include "Sawmill.h"
#include "Farm.h"
#include "NewBuilding.h"

void NewBuilding::perform() {
    Field * field = getFieldSelector()->getSelectedField();
    std::unique_ptr<Building> building;

    switch(getKind()){
        case BuildingKinds::SAWMILL:
            building = std::move(std::make_unique<Sawmill>(field));
        break;

        case BuildingKinds::FARM:
            building = std::move(std::make_unique<Farm>(field));
        break;
    }
    field->takeOwnership((Character *) getOwner());
    field->addBuilding(std::move(building));
}
