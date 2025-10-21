#include "Observer.h"

/**
 * @file Observer.cpp
 * @brief Implementation file for the Observer abstract base class in the Observer pattern.
 */
Observer::~Observer(){
    // Virtual destructor implementation (if needed)
    return;
};

void Observer::update(NurseryPlant* plant){
    // Pure virtual function; implementation will be provided in derived classes
    return;
};