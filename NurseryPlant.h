#ifndef NURSERYPLANT_H
#define NURSERYPLANT_H
#include "State.h"
#include "Subject.h"
#include <vector>
class NurseryPlant :public Subject {
    private:
        std::string name;
        State* currentState;
        std::vector<Observer*> observers;
    public:
        NurseryPlant(State* initialState,std::string name);
        ~NurseryPlant();
        void setState(State* newState);
        void performAction();
        std::string getStateName() const;
        void attach(Observer* observer) override;
        void detach(Observer* observer) override;
        void notify() override;
};

#endif
