#ifndef OBSERVER_H
#define OBSERVER_H
#include "state.h"
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(State state) = 0;
};

#endif