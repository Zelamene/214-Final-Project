#ifndef NURSERYPLANT_H
#define NURSERYPLANT_H
#include "State.h"
class NurseryPlant {
    private:
        State* currentState;
    public:
        NurseryPlant(State* initialState);
        ~NurseryPlant();
        void setState(State* newState);
        void performAction();
        std::string getStateName() const;
};

#endif