#pragma once

#include <string>
#include "World.h"

class Field {
protected:
    int x, y;
    std::string kind;
    std::string name;
    std::unique_ptr<World> world;

public:
    Field(int x, int y, World *world = nullptr);
    virtual ~Field();

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

    const std::unique_ptr<World>& getWorld() const {
        return world;
    }

    void setWorld(const std::unique_ptr<World>& world) {
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
};
