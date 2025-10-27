#include "CrateFactory.h"
#include "Crate.h"
#include <iostream>

Container* CrateFactory::createContainer(){
    
    std::string material;
    std::cout << "Please enter the material you would want for your crate (container) : " << std::endl;
    std::cin >> material;
    return new Crate(material);
}