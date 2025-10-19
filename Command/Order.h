/**
 * @file Order.h
 * @brief Represents a customer's plant order.
 */

#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include "NurseryPlant.h"
#include "Customer.h"
#include "Command.h"

/**
 * @class Order
 * @brief Stores details of a plant order.
 */
class Order {
private:
    int id; ///< Unique order ID
    std::string plantName; ///< Name of the plant ordered
    std::string state; ///< Current state of the order
    Customer* customer; ///< Pointer to the customer

public:
    /**
     * @brief Constructs an order.
     * @param i Order ID
     * @param plant Name of the plant
     * @param c Pointer to the customer
     */
    Order(int i, std::string plant, Customer* c)
        : id(i), plantName(plant), customer(c), state("pending") {}

    std::string getState() const { return state; }
    void setState(std::string s) { state = s; }
    std::string getPlantName() const { return plantName; }
    int getId() const { return id; }
    Customer* getCustomer() const { return customer; }
};

#endif
