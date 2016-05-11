#pragma once

#include <game/world/Field.h>
#include <game/world/materials/Tree.h>

class Forest : public Field {
private:
    int treesCount;
    Tree tree;

public:
    Forest(int x, int y, World * world);

    std::string getDescription();

    void randomize();

    int getTreesCount() const {
        return treesCount;
    }

    void setTree(std::string name);

    const Tree &getTree() const {
        return tree;
    }

    void setTreesCount(int treesCount) {
        Forest::treesCount = treesCount;
    }
};
