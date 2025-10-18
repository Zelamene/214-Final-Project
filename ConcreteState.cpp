#include "ConcreteState.h"
#include "NurseryPlant.h"
#include <iostream>


void SeedlingState::handleAction(NurseryPlant* plant) {
    std::cout << "The plant is a seedling. It needs water and sunlight to grow.\n";
    plant->setState(new SproutState());
}