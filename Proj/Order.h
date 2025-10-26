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
    Order(int i, std::string plant, Customer* c);
    std::string getState();
    void setState(std::string s);
    std::string getPlantName();
    int getId();
    Customer* getCustomer();
};

#endif
