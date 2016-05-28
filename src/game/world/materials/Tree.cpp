#include "Tree.h"


Tree::Tree() {}

Tree::Tree(std::string name) : name(name) {}

std::string Tree::randomizeTreeKind() {
    int size = sizeof(treesKinds) / 8;
    return treesKinds[rand() % size];
}
