#pragma once

#include "MapModeRenderer.h"

class TreesMode : public MapModeRenderer{

public:
    TreesMode(sf::Sprite *sprite, Field *field);

    virtual void render() override;
};
