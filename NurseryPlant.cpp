/**
 * @file NurseryPlant.cpp
 * @brief Implementation of the NurseryPlant class.
 */

#include "NurseryPlant.h"
#include <algorithm>

/**
 * @brief Constructs a NurseryPlant with an initial state and name.
 * @param initialState Pointer to the initial state object.
 * @param plantName The name of the plant.
 */
NurseryPlant::NurseryPlant(State* initialState, std::string plantName)
    : currentState(initialState), name(plantName) {
}

/**
 * @brief Destructor for NurseryPlant.
 */
NurseryPlant::~NurseryPlant() {
    delete currentState;
}

/**
 * @brief Sets a new state for the plant and notifies observers.
 * @param newState Pointer to the new state object.
 */
void NurseryPlant::setState(State* newState) {
    delete currentState;
    currentState = newState;
    notify();
}

/**
 * @brief Gets the name of the plant.
 * @return The name of the plant as a string.
 */
std::string NurseryPlant::getName() const {
    return name;
}

/**
 * @brief Starts the growing process by transitioning through states until mature.
 */
void NurseryPlant::startGrowing() {
    while (this->getStateName() != "Mature") {
        currentState->handleAction(this);
    }
}

/**
 * @brief Gets the name of the current state.
 * @return The name of the current state as a string.
 */
std::string NurseryPlant::getStateName() const {
    return currentState->getStateName();
}

/**
 * @brief Attaches an observer to this plant.
 * @param observer Pointer to the observer to attach.
 */
void NurseryPlant::attach(Observer* observer) {
    observers.push_back(observer);
}

/**
 * @brief Detaches an observer from this plant.
 * @param observer Pointer to the observer to detach.
 */
void NurseryPlant::detach(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

/**
 * @brief Notifies all attached observers of a state change.
 */
void NurseryPlant::notify() {
    for (Observer* obs : observers) {
        obs->update(this);
    }
}


