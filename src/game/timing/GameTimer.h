#pragma once

#include <SFML/System/Clock.hpp>
#include <thread>
#include <Observable.h>

class GameTimer : public Observable {
private:
    sf::Clock clock;
    unsigned int tickDuration;
    unsigned int ticks;
    std::thread ticker;
    bool running;
public:
    GameTimer(unsigned int tickDuration = 1000);
    ~GameTimer();
    void start();
    void tick();
};