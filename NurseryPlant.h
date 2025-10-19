#ifndef NURSERYPLANT_H
#define NURSERYPLANT_H

#include "Order.h"
#include <iostream>
using namespace std;

/**
 * @class NurseryPlant
 * @brief Represents a single plant order in the nursery system.
 *
 * This is a leaf class in the Composite design pattern.
 * It implements all abstract methods from the Order base class.
 */
class NurseryPlant : public Order
{
public:
    /**
     * @brief Constructs a NurseryPlant object.
     * @param price Base price of the plant.
     */
    NurseryPlant(double price);

    /**
     * @brief Destructor for NurseryPlant.
     */
    virtual ~NurseryPlant();

    /**
     * @copydoc Order::getTotal()
     * @override
     */
    double getTotal() override;

    /**
     * @copydoc Order::displayDetails()
     * @override
     */
    void displayDetails() override;

    /**
     * @copydoc Order::calculateTax()
     * @override
     */
    void calculateTax() override;

    /**
     * @brief Creates and returns a clone of this object.
     * @return Pointer to a new NurseryPlant object (deep copy).
     */
    Order *clone() const override;
};

#endif
