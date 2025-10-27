#include "Aloe.h"

Aloe::Aloe(){
    description = "Aloe";
    basePrice = 250.0;
};

std::string Aloe::getDescription() {
    return description;
};

double Aloe::calculateCost() {
    return basePrice;
};

Aloe::~Aloe() {
    
};