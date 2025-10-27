#include "Baobab.h"

Baobab::Baobab(){
    description = "Baobab";
    basePrice = 100.0;
};

std::string Baobab::getDescription() {

    return description;
};

double Baobab::calculateCost() {
    return basePrice;
};

Baobab::~Baobab() {
    
};

