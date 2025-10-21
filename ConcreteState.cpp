/**
 * @file ConcreteState.cpp
 * @brief Implementation of concrete state classes.
 */

#include "ConcreteState.h"
#include "NurseryPlant.h"
#include <iostream>

/**
 * @brief Handles the action for the Seedling state.
 *
 * Simulates planting and potential growth. With a 20% chance, the seedling continues growing;
 * otherwise, it transitions to Sprout state.
 * @param plant Pointer to the NurseryPlant object.
 */
void SeedlingState::handleAction(NurseryPlant* plant) {
    std::cout << "The " << plant->getName() << " Planted\n";
    bool stillGrowing = (rand() % 100) < 20;
    if (stillGrowing) {
        std::cout << "The seedling is still growing. It needs more time.\n";
        return;
    }
    plant->setState(new SproutState());
}

/**
 * @brief Gets the name of the Seedling state.
 * @return "Seedling"
 */
std::string SeedlingState::getStateName() const {
    return "Seedling";
}

/**
 * @brief Handles the action for the Sprout state.
 *
 * Simulates sprout growth. With a 90% chance, it matures; otherwise, it may be attacked by pests and wilt.
 * @param plant Pointer to the NurseryPlant object.
 */
void SproutState::handleAction(NurseryPlant* plant) {
    std::cout << "The " << plant->getName() << " is a sprout. It is growing leaves and needs nutrients.\n";
    bool readyToMature = (rand() % 100) < 90;
    if (!readyToMature) {
        std::cout << "The sprout( " << plant->getName() << " ) is still developing. It needs more care.\n";
        return;
    }

    bool pestAttack = (rand() % 100) < 10;
    if (pestAttack) {
        std::cout << "Oh no! The sprout( " << plant->getName() << " ) was attacked by pests and is wilting.\n";
        plant->setState(new WiltingPlantState());
        return;
    }
    plant->setState(new MatureState());
}

/**
 * @brief Gets the name of the Sprout state.
 * @return "Sprout"
 */
std::string SproutState::getStateName() const {
    return "Sprout";
}

/**
 * @brief Handles the action for the Mature state.
 *
 * Simulates mature plant behavior, then transitions to Wilting state.
 * @param plant Pointer to the NurseryPlant object.
 */
void MatureState::handleAction(NurseryPlant* plant) {
    std::cout << "The " << plant->getName() << " is mature. It is flowering and may need pruning.\n";
    plant->setState(new WiltingPlantState());
}

/**
 * @brief Gets the name of the Mature state.
 * @return "Mature"
 */
std::string MatureState::getStateName() const {
    return "Mature";
}

/**
 * @brief Handles the action for the Wilting state.
 *
 * Simulates wilting and recovery by transitioning back to Seedling state.
 * @param plant Pointer to the NurseryPlant object.
 */
void WiltingPlantState::handleAction(NurseryPlant* plant) {
    std::cout << "The " << plant->getName() << " is wilting. It needs immediate care to recover.\n";
    plant->setState(new SeedlingState());
}

/**
 * @brief Gets the name of the Wilting state.
 * @return "Wilting"
 */
std::string WiltingPlantState::getStateName() const {
    return "Wilting";
}
