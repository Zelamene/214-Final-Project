#ifndef OBSERVER_H
#define OBSERVER_H
#include "State.h"
class NurseryPlant;
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(NurseryPlant* plant) = 0;
};

#endif
