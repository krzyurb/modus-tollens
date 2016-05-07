#include <iostream>
#include "GameTimer.h"

GameTimer::GameTimer(unsigned int tickDuration) : tickDuration(tickDuration), ticks(0) {

}

void GameTimer::start() {
    clock.restart();
    ticker = std::thread(&GameTimer::tick, this);
    ticker.detach();
}

void GameTimer::tick() {
    while (true) {
        if (clock.getElapsedTime().asMilliseconds() == tickDuration) {
            std::cout << "tick " << ++ticks << '\n';
            clock.restart();
        }
    }
}