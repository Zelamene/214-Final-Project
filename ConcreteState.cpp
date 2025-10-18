#include "ConcreteState.h"
#include "NurseryPlant.h"
#include <iostream>


void SeedlingState::handleAction(NurseryPlant* plant) {
    std::cout << "The plant is a seedling. It needs water and sunlight to grow.\n";
    plant->setState(new SproutState());
}
std::string SeedlingState::getStateName() const {
    return "Seedling";
}

void SproutState::handleAction(NurseryPlant* plant) {
    std::cout << "The plant is a sprout. It is growing leaves and needs nutrients.\n";
    plant->setState(new MatureState());
}
std::string SproutState::getStateName() const {
    return "Sprout";
}
void MatureState::handleAction(NurseryPlant* plant) {
    std::cout << "The plant is mature. It is flowering and may need pruning.\n";
    plant->setState(new WiltingPlantState());
}
std::string MatureState::getStateName() const {
    return "Mature";
}
void WiltingPlantState::handleAction(NurseryPlant* plant) {
    std::cout << "The plant is wilting. It needs immediate care to recover.\n";
    plant->setState(new SeedlingState());
}
std::string WiltingPlantState::getStateName() const {
    return "Wilting";
}