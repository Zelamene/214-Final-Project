#include "Rose.h"

Rose::Rose(){
    description = "Rose";
    basePrice = 200.0;
};

std::string Rose::getDescription() {

    return description;
};

double Rose::calculateCost() {
    return basePrice;
};

Rose::~Rose() {
};

