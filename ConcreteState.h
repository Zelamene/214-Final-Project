#ifndef CONCRETESTATE_H
#define CONCRETESTATE_H

#include "State.h"
#include "NurseryPlant.h"

class SeedlingState : public State {
public:

    void handleAction(NurseryPlant* plant) override;
    std::string getStateName() const override;
};
class SproutState : public State {
public:
    void handleAction(NurseryPlant* plant) override;
    std::string getStateName() const override;
};
class MatureState : public State {
public:
    void handleAction(NurseryPlant* plant) override;
    std::string getStateName() const override;
};
class WiltingPlantState : public State {
public:
    void handleAction(NurseryPlant* plant) override;
    std::string getStateName() const override;
};

#endif // CONCRETESTATE_H