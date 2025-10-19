#include "Staff.h"
#include "NurseryPlant.h"
#include <iostream>

void Staff::update(NurseryPlant* plant) {
    std::cout << "Staff notified: Plant '" << plant->getStateName() << "' state changed." << std::endl;
}
std::string Staff::getName() const {
    return "Staff Member";
}
