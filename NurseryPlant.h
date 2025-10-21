#ifndef NURSERYPLANT_H
#define NURSERYPLANT_H

#include "Order.h"
#include <string>
#include <iostream>
using namespace std;

/**
 * @class NurseryPlant
 * @brief Abstract representation of a plant in the nursery.
 *
 * Serves as the base class for all plant types such as FloweringPlant and Tree.
 * This class also functions as a leaf in the Composite design pattern,
 * implementing the abstract methods from the Order base class.
 */
class NurseryPlant : public Order
{
protected:
    string name;
    string maintenanceType;

public:
    /**
     * @brief Virtual destructor for safe polymorphic deletion.
     */
    virtual ~NurseryPlant();

    /**
     * @brief Constructor
     */
    NurseryPlant(const string &name, const string &maintenanceType, double price);

    /**
     * @brief getter for the name of the plant (e.g rose, baobab etc).
     */
    string getName() const;

    /**
     * @brief getter for the maintenance Type of the plant.
     */
    string getMaintenanceType() const;

    /**
     * @brief Display information about the plant.
     */
    virtual void displayInfo() const;

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
