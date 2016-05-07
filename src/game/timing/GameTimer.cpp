#include <iostream>
#include "GameTimer.h"

GameTimer::GameTimer(unsigned int tickDuration) : tickDuration(tickDuration), ticks(0), running(false) {
}

GameTimer::~GameTimer() {
    running = false;
}

void GameTimer::start() {
    clock.restart();
    running = true;
    ticker = std::thread(&GameTimer::tick, this);
    ticker.detach();
}

void GameTimer::tick() {
    while (running) {
        if (clock.getElapsedTime().asMilliseconds() >= (sf::Int32)tickDuration) {
            ++ticks;
            notifyAll();
            clock.restart();
        }
    }
}