#include <iostream>
#include "NurseryPlant.h"
#include "ConcreteState.h"
#include "Staff.h"
#include "Inventory.h"

int main() {
    NurseryPlant* rose = new NurseryPlant(new SeedlingState(), "Rose");
    NurseryPlant* tree = new NurseryPlant(new SeedlingState(), "tree");

    Staff* staff = new Staff();

    rose->attach(staff);
    tree->attach(staff);

    std::cout << "Initial state: " << rose->getStateName() << std::endl;

    /*
    Awes✌️✌️ im not yet done with this code but other wise piece.
    */
    rose->performAction();
    rose->performAction();
    rose->performAction();
    rose->performAction();
    tree->performAction();
    tree->performAction();
    tree->performAction();
    tree->performAction();

    Inventory inventory;
    inventory.addPlant("Rose", rose);
    inventory.addPlant("Rose", rose);
    inventory.addPlant("Tree", tree);

    inventory.displayInventory();

    delete rose;
    delete staff;

    return 0;
}
