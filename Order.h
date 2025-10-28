#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <chrono>
#include <random>
#include <sstream>
#include <iomanip>
#include "Iterator.h"
using namespace std;


/**
 * @class Order
 * @brief Abstract base class representing an order.
 *
 * Provides a common interface for all types of orders.
 * Implements the Prototype pattern through the clone() method.
 */
class Order
{
protected:
    /** @brief Unique identifier for the order. */
    string orderID;

    /** @brief Base price of the order (before tax). */
    double price;

    /** @brief Default tax rate applied to all orders. */
    double taxRate = 0.15;

public:
    /**
     * @brief Constructs an Order with a given ID and price.
     * @param price Base price of the order.
     */
    Order(double price);

    Order();

    /**
     * @brief Virtual destructor for Order.
     */
    virtual ~Order();

    /**
     * @brief Calculates and returns the total cost including tax.
     * @return Total price with tax.
     */
    virtual double getTotal() = 0;

    /**
     * @brief Displays order details to the output.
     */
    virtual void displayDetails() = 0;

    /**
     * @brief Calculates and/or displays the tax amount.
     */
    virtual void calculateTax() = 0;

    /**
     * @brief Creates and returns a deep copy of this order.
     * @return Pointer to a cloned Order object.
     */
    virtual Order *clone() const = 0;

    /**
     * @brief Return the identifier of an order.
     *
     */
    virtual string getID();

   
};

#endif
