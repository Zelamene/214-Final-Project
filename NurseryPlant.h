#ifndef NURSERYPLANT_H
#define NURSERYPLANT_H
#include "State.h"
#include "Subject.h"
class NurseryPlant :public Subject {
    private:
        std::string name;
        State* currentState;
    public:
        NurseryPlant(State* initialState,std::string name);
        ~NurseryPlant();
        void setState(State* newState);
        void performAction();
        std::string getStateName() const;
};

#endif