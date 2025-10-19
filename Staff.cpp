/**
 * @file Staff.cpp
 * @brief Implementation of the Staff class.
 */

#include "Staff.h"
#include "NurseryPlant.h"
#include "Inventory.h"
#include <iostream>

/**
 * @brief Constructs a Staff object with a reference to the inventory.
 * @param inventory Pointer to the Inventory object.
 */
Staff::Staff(Inventory* inventory) : inventory(inventory) {
}

/**
 * @brief Updates the staff when a plant's state changes.
 *
 * Prints a notification and adds the plant to inventory if it is mature.
 * @param plant Pointer to the NurseryPlant that changed state.
 */
void Staff::update(NurseryPlant* plant) {
    std::cout << "Staff notified: Plant '" << plant->getStateName() << "' state changed.\n" << std::endl;
    if (plant->getStateName() == "Mature") {
        inventory->addPlant(plant->getName(), plant);
        std::cout << "Staff added plant to inventory." << std::endl;
    }
}

/**
 * @brief Gets the name of the staff member.
 * @return "Staff Member"
 */
std::string Staff::getName() const {
    return "Staff Member";
}
