#include "Player.h"

const Stock &Player::getStock() const {
    return stock;
}

void Player::render(Renderer & renderer) {
    renderer.drawPlayer(*this);
}