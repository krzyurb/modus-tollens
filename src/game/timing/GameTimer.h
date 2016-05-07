#pragma once

#include <SFML/System/Clock.hpp>
#include <thread>

class GameTimer {
private:
    sf::Clock clock;
    unsigned int tickDuration;
    unsigned int ticks;
    std::thread ticker;
public:
    GameTimer(unsigned int tickDuration = 1000);
    void start();
    void tick();
};