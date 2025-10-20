#include "Order.h"
#include <iostream>
#include "Customer.h"

Order::Order(int i, std::string plant, Customer* c)
    : id(i), plantName(plant), state("pending"), customer(c) {

    }


    void Order::setState(std::string s) { state = s; }

    int Order::getId() 
     { 
        return id; 
    }
    
    std :: string Order::getState() 
     { 
        return state;
     }

    Customer *Order::getCustomer() 
     { 
        return customer; 
    }

std::string Order::getPlantName() {
    return plantName;
}