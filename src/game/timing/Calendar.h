#include "Observer.h"
#include <string>

class Calendar : public Observer {
private:
    unsigned int ticksPerDay;
    unsigned int day;
public:
    Calendar(unsigned int ticksPerDay = 10) : ticksPerDay(ticksPerDay), day(1) {}
    unsigned int getDay() const {
        return day;
    }

    void update(Observable * o);

    operator std::string();
};
