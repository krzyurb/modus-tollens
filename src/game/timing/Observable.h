#pragma once

#include <list>
#include "Observer.h"

class Observer;

class Observable {
private:
    std::list<Observer*> observers;
public:
    virtual ~Observable() = 0;
    virtual void addObserver(Observer * o);
    virtual void notifyAll();
};
