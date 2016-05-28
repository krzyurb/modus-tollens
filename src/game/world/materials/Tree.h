#pragma once

#include <string>
#include <stdlib.h>

static const char * treesKinds[] = { "birch", "oak" };

class Tree {
private:
    std::string name;
    int endurance;

public:

    Tree();

    Tree(std::string name);

    static std::string randomizeTreeKind();

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Tree::name = name;
    }

    int getEndurance() const {
        return endurance;
    }

    void setEndurance(int endurance) {
        Tree::endurance = endurance;
    }
};
