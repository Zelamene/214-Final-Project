#include "ConcreteState.h"
#include "NurseryPlant.h"
#include <iostream>

void SeedlingState::handleAction(NurseryPlant* plant) {
    std::cout << "The " << plant->getName() << " Planted\n";
    bool stillGrowing = (rand() % 100) < 50;
    if (stillGrowing) {
        std::cout << "The seedling is still growing. It needs more time.\n";
        return;
    }

    plant->setState(new SproutState());
}

std::string SeedlingState::getStateName() const {
    return "Seedling";
}

void SproutState::handleAction(NurseryPlant* plant) {
    std::cout << "The " << plant->getName() << " is a sprout. It is growing leaves and needs nutrients.\n";

        if(plant->getWaterLevel()<=5){
        std::cout << "Oh no! The sprout( " << plant->getName() << " ) died due to lack of water.\n";
        plant->setWaterlevel(100);
        plant->setState(new WiltingPlantState());
        return;
    }
    bool readyToMature = (rand() % 100) < 50;
    if (!readyToMature) {
        std::cout << "The sprout( " << plant->getName() << " ) is still developing. It needs more care.\n";
        return;
    }



    bool pestAttack = (rand() % 100) < 20;
    if (pestAttack) {
        std::cout << "Oh no! The sprout( " << plant->getName() << " ) was attacked by pests and is wilting.\n";
        plant->setState(new WiltingPlantState());
        return;
    }
    plant->setState(new MatureState());
}

std::string SproutState::getStateName() const {
    return "Sprout";
}

void MatureState::handleAction(NurseryPlant* plant) {
    std::cout << "The " << plant->getName() << " is mature. It is flowering and may need pruning.\n";
    plant->setState(new WiltingPlantState());
}

std::string MatureState::getStateName() const {
    return "Mature";
}

void WiltingPlantState::handleAction(NurseryPlant* plant) {
    std::cout << "The " << plant->getName() << " is wilting. It needs immediate care to recover.\n";

    plant->setState(new SeedlingState());
}

std::string WiltingPlantState::getStateName() const {
    return "Wilting";
}
