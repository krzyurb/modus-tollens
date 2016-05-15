#include "Player.h"

Player::Player() {
    stock = {0};
}

const Stock &Player::getStock() const {
    return stock;
}

void Player::render(Renderer & renderer) {
    renderer.drawPlayer(*this);
}