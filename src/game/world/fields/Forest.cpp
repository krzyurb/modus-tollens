#include <GameData.hpp>
#include "Forest.h"

Forest::Forest(int x, int y, World * world) : Field(x, y, world) {
    this->kind = "forest";
}

void Forest::randomize(){
    setTreesCount(rand() % 1000);
    setTree(Tree::randomizeTreeKind());
}

void Forest::setTree(std::string name) {
    int endurance = GameData::read<int>("materials/trees", name + ".endurance");

    this->tree = Tree(name);
    this->tree.setEndurance(endurance);
}

std::string Forest::getDescription(){
    std::stringstream desc;
    desc << "Trees: " <<this->getTree().getName();
    desc << " (" << this->getTreesCount() << ")" << "\n";
    desc << "Endurance: " <<this->getTree().getEndurance() << "\n";
    desc << "\n\nBuildings: \n" << getBuildingsDescription();
    return desc.str();
}

void Forest::cutTrees(int count) {
    treesCount -= count;
}
