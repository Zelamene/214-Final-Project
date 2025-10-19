#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <vector>
#include "NurseryPlant.h"
#include "Customer.h"
#include "Command.h"

class Order {
private:
    int id;
    std :: string plantName;
    std :: string state;  // "pending", "ready", "processed"
    Customer* customer;

public:
    Order(int i, std :: string plant, Customer* c)
        : id(i), plantName(plant), customer(c), state("pending") {}

    std :: string getState() const { return state; }
    void setState(std :: string s) { state = s; }
    std :: string getPlantName() const { return plantName; }
    int getId() const { return id; }
    Customer* getCustomer() const { return customer; }
};

#endif