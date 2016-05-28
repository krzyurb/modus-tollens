#pragma once

#include <string>
#include <memory>
#include <iostream>
#include "World.h"
#include "Renderer.h"
#include "Character.h"
#include "Building.h"

class Renderer;
class World;
class Building;

class Field {
protected:
    int x, y;
    int id;
    std::string kind;
    std::string name;
    World * world;
    Character * owner;
    std::vector<std::unique_ptr<Building>> buildings;

public:
    Field(int x, int y, World * world);

    void takeOwnership(Character * character);

    operator std::string();

    void render(Renderer &renderer, bool dark = false)const;

    virtual std::string getDescription();

    std::string getBuildingsDescription();

    virtual void randomize();

    std::vector<Field*> getNeighbors();

    void addBuilding(std::unique_ptr<Building> &&building);

    const std::string& getKind() const {
        return kind;
    }

    void setKind(const std::string& kind) {
        this->kind = kind;
    }

    const std::string& getName() const {
        return name;
    }

    void setName(const std::string& name) {
        this->name = name;
    }

    World * getWorld() {
        return world;
    }

    void setWorld(World * world) {
        this->world = world;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        this->x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        this->y = y;
    }

    void setId(int id){
        this->id = id;
    }

    size_t getId(){
        return id;
    }

    const std::vector<std::unique_ptr<Building>> &getBuildings() const {
        return buildings;
    }
};
