#ifndef NURSERYPLANT_H
#define NURSERYPLANT_H
#include "State.h"
class NurseryPlant {
    private:
        State* currentState;


    public:
        NurseryPlant(State* initialState) : currentState(initialState) {}
        
        ~NurseryPlant() {
            delete currentState;
        }

        void setState(State* newState) {
            delete currentState;
            currentState = newState;
        }

        void performAction() {
            currentState->handleAction(this);
        }

        std::string getStateName() const {
            return currentState->getStateName();
        }

};

#endif