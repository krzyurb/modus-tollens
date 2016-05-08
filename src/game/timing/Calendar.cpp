#include "Calendar.h"
#include "GameTimer.h"
#include <iostream>
#include <sstream>

void Calendar::update(Observable *o) {
    GameTimer * timer = dynamic_cast<GameTimer*>(o);
    if(timer->getTicks() % ticksPerDay == 0) ++day;
}

Calendar::operator std::string() {
    std::stringstream result;
    result << "Day: " << this->getDay() << "\n";
    result << "Week: " << this->getDay() / 7;
    return result.str();
}
