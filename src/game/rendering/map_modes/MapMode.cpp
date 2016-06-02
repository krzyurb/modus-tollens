#include "MapMode.h"
#include "FertilityMode.h"
#include "NormalMode.h"
#include "TreesMode.h"
#include "BuildingMode.h"

std::vector<std::unique_ptr<MapMode>> MapMode::modes = std::vector<std::unique_ptr<MapMode>>();

void MapMode::init() {
    modes.push_back(std::make_unique<NormalMode>());
    modes.push_back(std::make_unique<FertilityMode>());
    modes.push_back(std::make_unique<TreesMode>());
    modes.push_back(std::make_unique<BuildingMode>());
}