#include "Crate.h"
#include <iostream>

Crate::Crate(const std::string& material)
    : material(material)
{
    std::cout << "Crate created with material: " << material << std::endl;
}