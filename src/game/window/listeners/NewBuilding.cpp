#include "NewBuilding.h"

void NewBuilding::perform() {
    Field * field = getFieldSelector()->getSelectedField();
    switch(getKind()){
        case ""
    }
    Field * city  = new City(field->getX(), field->getY(), field->getWorld());
    field->getWorld()->setField(field->getId(), city);
    getFieldSelector()->setSelectedField(city);
}
