#include <iostream>
#include <string>
#include "NurseryPlant.h"
#include "ConcreteState.h"
#include "Staff.h"
#include "Inventory.h"

int main() { 
    Inventory* storage=new Inventory();
    NurseryPlant* rose = new NurseryPlant(new SeedlingState(), std::string("Rose") );
    NurseryPlant* tree = new NurseryPlant(new SeedlingState(),std::string("Tree") );
    Staff* staff = new Staff(storage);

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

    
    // inventory.addPlant("Rose", rose);
    // inventory.addPlant("Rose", rose);
    // inventory.addPlant("Tree", tree);

    storage->displayInventory();

    delete rose;
    delete staff;

    return 0;
}
