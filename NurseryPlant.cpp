#include "NurseryPlant.h"
#include <algorithm>

NurseryPlant::NurseryPlant(State* initialState,std::string name):currentState(initialState),name(name) {}
NurseryPlant::~NurseryPlant() {
    delete currentState;
}

void NurseryPlant::setState(State* newState) {
    delete currentState;
    currentState = newState;
    notify();
}

void NurseryPlant::performAction(){
    currentState->handleAction(this);

}

std::string NurseryPlant::getStateName() const {
    return currentState->getStateName();
}

void NurseryPlant::attach(Observer* observer) {
    observers.push_back(observer);
}

void NurseryPlant::detach(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void NurseryPlant::notify() {
    for (Observer* obs : observers) {
        obs->update(this);
    }
}


