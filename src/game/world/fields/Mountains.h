#pragma once

#include "Field.h"

class Mountains : public Field {
public:
    int stoneCount;

    Mountains(int x, int y, World *world);

    std::string getDescription();

    void randomize();

    void mineStone(int count);

    int getStoneCount(){
        return this->stoneCount;
    }

    void setStoneCount(int stoneCount){
        this->stoneCount = stoneCount;
    }
};
