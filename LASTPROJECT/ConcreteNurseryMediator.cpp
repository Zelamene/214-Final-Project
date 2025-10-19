#include "ConcreteNurseryMediator.h"
#include <iostream>

ConcreteNurseryMediator::ConcreteNurseryMediator() : inventory(nullptr) {};

ConcreteNurseryMediator::~ConcreteNurseryMediator() {};


void ConcreteNurseryMediator::addCustomer(Customer* customer) {
    customer->setMediator(this);
    customers.push_back(customer);
};

void ConcreteNurseryMediator::addStaff(Staff* staff) {
    staff->setMediator(this);
    staffMembers.push_back(staff);
};

void ConcreteNurseryMediator::setInventory(Inventory* inv) {
    inventory = inv;
    if (inventory) {
        inventory->setMediator(this);
    }
};


void ConcreteNurseryMediator::notify(Participant* sender, const std::string& event) {
    std::string senderType = getSenderType(sender);
    
    std::cout << "\n--- Mediator Routing ---" << std::endl;
    std::cout << "From: " << sender->getName() << " (" << senderType << ")" << std::endl;
    std::cout << "Event: " << event << std::endl;
    std::cout << "Action: ";
    

    if (senderType == "Customer") {
        handleCustomerEvent(sender, event);
    } else if (senderType == "Staff") {
        handleStaffEvent(sender, event);
    } else if (senderType == "Inventory") {
        handleInventoryEvent(sender, event);
    }
    std::cout << "-----------------------\n" << std::endl;
};
void ConcreteNurseryMediator::handleCustomerEvent(Participant* customer, const std::string& event) {
    std::string customerName = customer->getName();
    
    if (event.find("wants to purchase") != std::string::npos) {
        std::cout << "Processing purchase request" << std::endl;
        
        std::string plantName = event.substr(event.find("purchase") + 9);
        plantName = plantName.substr(0, plantName.find(" for"));
        
        if (inventory && inventory->hasStock(plantName)) {
            notifyStaff(customerName + " wants to purchase " + plantName);
            inventory->removePlant(plantName, 1);
        } else {
            customer->receive("Sorry, " + plantName + " is out of stock");
        }
    }
    else if (event.find("wants information about") != std::string::npos) {
        std::cout << "Forwarding to plant expert" << std::endl;
        notifyStaff(customerName + " needs plant information: " + event);
    }
    else if (event.find("needs assistance") != std::string::npos) {
        std::cout << "Alerting staff for assistance" << std::endl;
        notifyStaff("ASSISTANCE NEEDED: " + customerName + " at sales floor");
    }
    else {
        std::cout << "Broadcasting customer activity" << std::endl;
        notifyStaff("Customer activity: " + event);
    }
};

void ConcreteNurseryMediator::handleStaffEvent(Participant* staff, const std::string& event) {
    if (event.find("needs stock check") != std::string::npos) {
        std::cout << "Checking inventory" << std::endl;
        if (inventory) {
            std::string plantName = event.substr(event.find("for") + 4);
            inventory->checkStock(plantName);
        }
    }
    else if (event.find("processing payment") != std::string::npos) {
        std::cout << "Recording transaction" << std::endl;
        notifyCustomers("Payment being processed: " + event);
    }
    else {
        std::cout << "Broadcasting staff activity" << std::endl;
        notifyCustomers("Staff update: " + event);
        if (inventory) {
            inventory->receive("Staff activity: " + event);
        }
    }
};

void ConcreteNurseryMediator::handleInventoryEvent(Participant* inv, const std::string& event) {
    if (event.find("added") != std::string::npos) {
        std::cout << "New stock available" << std::endl;
        notifyStaff("New plants available: " + event);
        notifyCustomers("New plants just arrived!");
    }
    else if (event.find("removed") != std::string::npos) {
        std::cout << "Stock updated" << std::endl;
        notifyStaff("Inventory updated: " + event);
    }
    else {
        std::cout << "Inventory activity" << std::endl;
        notifyStaff("Inventory update: " + event);
    }
};


void ConcreteNurseryMediator::notifyCustomers(const std::string& message) {
    for (auto* customer : customers) {
        customer->receive(message);
    }
}

void ConcreteNurseryMediator::notifyStaff(const std::string& message) {
    for (auto* staff : staffMembers) {
        staff->receive(message);
    }
};

std::string ConcreteNurseryMediator::getSenderType(Participant* sender) {
    if (dynamic_cast<Customer*>(sender)) return "Customer";
    if (dynamic_cast<Staff*>(sender)) return "Staff";
    if (dynamic_cast<Inventory*>(sender)) return "Inventory";
    return "Unknown";
};