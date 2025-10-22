#include <iostream>
#include <string>
#include "NurseryPlant.h"
#include "ConcreteState.h"
#include "Staff.h"
#include "Inventory.h"

int main() {
    Inventory* storage = new Inventory();
    NurseryPlant* rose = new NurseryPlant(new SeedlingState(), std::string("Rose"));
    NurseryPlant* tree = new NurseryPlant(new SeedlingState(), std::string("Tree"));

    Staff* staff = new Staff(storage);

    rose->attach(staff);
    tree->attach(staff);


    std::cout << "Initial state: " << rose->getStateName() << std::endl;
    rose->startGrowing();
    tree->startGrowing();

    storage->displayInventory();
    storage->removePlant("Rose");
    storage->displayInventory();

    delete rose;
    delete tree;
    delete staff;
    delete storage;

    return 0;
}
