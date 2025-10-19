#include <iostream>
#include "NurseryPlant.h"
#include "ConcreteState.h"
#include "Staff.h"
#include "Inventory.h"

int main() {
    // Create a plant in seedling state
    NurseryPlant* rose = new NurseryPlant(new SeedlingState(), "Rose");
    NurseryPlant* tree = new NurseryPlant(new SeedlingState(), "tree");

    // Create staff observer
    Staff* staff = new Staff();

    // Attach staff to plant
    rose->attach(staff);
    tree->attach(staff);

    // Perform actions to transition states
    std::cout << "Initial state: " << rose->getStateName() << std::endl;
    rose->performAction(); // Seedling -> Sprout
    rose->performAction(); // Sprout -> Mature
    rose->performAction(); // Mature -> Wilting
    rose->performAction(); // Wilting -> Seedling
    tree->performAction(); // Seedling -> Sprout
    tree->performAction(); // Sprout -> Mature
    tree->performAction(); // Mature -> Wilting
    tree->performAction(); // Wilting -> Seedling

    // Create inventory and add plant
    Inventory inventory;
    inventory.addPlant("Rose", rose);
    inventory.addPlant("Rose", rose);
    inventory.addPlant("Tree", tree);

    inventory.displayInventory();

    // Clean up
    delete rose;
    delete staff;

    return 0;
}
