#include "Staff.h"
#include "NurseryPlant.h"
#include "Inventory.h"
#include <iostream>


Staff::Staff(Inventory* inventory) : inventory(inventory) {
}

Staff::~Staff(){
    
}

void Staff::update(NurseryPlant* plant) {
    std::cout << "Staff notified: Plant '" << plant->getStateName() << "' state changed.\n" << std::endl;
    if (plant->getStateName() == "Mature") {
        inventory->addPlant(plant->getName(), plant);
        std::cout << "Staff added plant to inventory." << std::endl;
    }
}

std::string Staff::getName() const {
    return "Staff Member";
}
