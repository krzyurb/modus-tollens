#include "Calendar.h"
#include "GameTimer.h"
#include <iostream>

void Calendar::update(Observable *o) {
    GameTimer * timer = dynamic_cast<GameTimer*>(o);
    if(timer->getTicks() % ticksPerDay == 0) ++day;
}