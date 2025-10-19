#include "NurseryPlant.h"

NurseryPlant::NurseryPlant(State* initialState,std::string name):currentState(initialState),name(name) {}
NurseryPlant::~NurseryPlant() {
    delete currentState;
}

void NurseryPlant::setState(State* newState) {
    delete currentState;
    currentState = newState;
}

void NurseryPlant::performAction(){
    currentState->handleAction(this);

}

std::string NurseryPlant::getStateName() const {
    return currentState->getStateName();
}


