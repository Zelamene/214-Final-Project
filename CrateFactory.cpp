#include "CrateFactory.h"
#include "Crate.h"
#include <iostream>

Container* CrateFactory::createContainer(){
    std::cout << "Creating a wooden crate conatiner." << std::endl;
    return new Crate("Wood");
}