#include "Observable.h"

Observable::~Observable() { }

void Observable::addObserver(Observer *o) {
    observers.push_back(o);
}

void Observable::notifyAll() {
    for(auto & o : observers)
        o->update(this);
}
