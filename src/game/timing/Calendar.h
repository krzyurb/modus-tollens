#include "Observer.h"

class Calendar : public Observer {
private:
    const unsigned int ticksPerDay = 1;
    unsigned int day;
public:
    unsigned int getDay() const {
        return day;
    }

    void update(Observable * o);
};
