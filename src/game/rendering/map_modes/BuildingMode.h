#pragma once

class BuildingMode : public MapMode {
public:
    virtual sf::Sprite getSprite(Field * field) const override;
};