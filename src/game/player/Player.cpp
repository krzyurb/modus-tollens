#include "Player.h"
#include "GameTimer.h"
#include <random>

Player::Player() {
    stock = {0};
}

Stock &Player::getStock() {
    return stock;
}

void Player::render(Renderer & renderer) {
    renderer.drawPlayer(*this);
}

void Player::update(Observable *o) {
    GameTimer * timer = dynamic_cast<GameTimer*>(o);
    if(timer != nullptr) {
        gather();
    }
}

void Player::gather() {
    std::uniform_real_distribution<double> unif(0, 1);
    std::default_random_engine re;
    stock.stone += 0;
    int workPoints = 5;

    for(auto &field : getFields()) {
        if(field->getKind() == "city"){
            workPoints += 10;
        }
    }
    stock.tools = workPoints;

    for(auto &field : getFields()){
        for(auto &building : field->getBuildings()) {
            building->produce(this);
        }
    }
}