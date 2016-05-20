#pragma once

#include <string>
#include <memory>

#include "World.h"
#include "Renderer.h"
#include "Character.h"

class Renderer;
class World;

class Field {
protected:
    int x, y;
    int id;
    std::string kind;
    std::string name;
    World * world;
    Character * owner;
public:
    Field(int x, int y, World * world);
    virtual ~Field();

    void takeOwnership(Character * character);

    operator std::string();

    void render(Renderer &renderer, bool dark = false)const;

    virtual std::string getDescription();

    virtual void randomize();

    std::vector<Field*> getNeighbors();

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

    int getId(){
        return id;
    }
};
