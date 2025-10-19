#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string& name, NurseryMediator* med) 
    : Participant(name, med) {}

void Customer::browsePlants() {
    send("is browsing available plants");
}

void Customer::requestPlantInfo(const std::string& plantType) {
    send("wants information about " + plantType);
}

void Customer::makePurchase(const std::string& plantName, double price) {
    send("wants to purchase " + plantName + " for R" + std::to_string(price));
}

void Customer::askForAssistance() {
    send("needs assistance at sales floor");
}