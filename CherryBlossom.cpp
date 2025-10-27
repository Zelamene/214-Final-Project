#include "CherryBlossom.h"

CherryBlossom::CherryBlossom(){
    description = "CherryBlossom";
    basePrice = 250.0;
};

std::string CherryBlossom::getDescription() {

    return description;
};

double CherryBlossom::calculateCost() {
    return basePrice;
};

CherryBlossom::~CherryBlossom() {
    
};

