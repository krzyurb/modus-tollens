#pragma once

#include <game/rendering/Renderer.h>
#include "MapModeRenderer.h"

class FertilityMode : public MapModeRenderer {

public:
    FertilityMode(sf::Sprite * sprite, Field *field);

    void render();
};
