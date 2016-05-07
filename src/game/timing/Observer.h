#pragma once

#include "Observable.h"

class Observable;

class Observer {
public:
    virtual ~Observer() {}
    virtual void update(Observable *o) = 0;
};