/**
 * @file Cashier.h
 * @brief Cashier class that uses PaymentStrategy as context.
 */

#ifndef CASHIER_H
#define CASHIER_H

#include "Staff.h"
#include "LowMaintenancePlantCare.h"
#include "Inventory.h"
#include "PaymentStrategy.h"
#include "Garden.h"
#include <iostream>
using namespace std;

/**
 * @class Cashier
 * @brief Handles customer transactions and manages sales using a PaymentStrategy.
 *
 * The Cashier class processes sales, updates the inventory, and can notify
 * when plants reach maturity. It interacts with the inventory directly so
 * that nursery staff are not required to be available at all times.
 *
 * @note The cashier has permission to modify the inventory as needed
 *       during customer transactions.
 */

class Cashier : public Staff
{
private:
    Garden *garden;
    PaymentStrategy *paymentStrategy;

public:
    /**
     * @brief Constructs a Cashier with access to the inventory.
     * @param inventory Pointer to the Inventory object.
     * @param name Name of the cashier.
     * @param garden Pointer to the Garden object.
     */
    Cashier(Inventory *inventory, const string &name, Garden *garden);

    /**
     * @brief Default destructor.
     */
    virtual ~Cashier() = default;

    /**
     * @brief Processes a sale for a given plant with payment.
     * @param plantName The name of the plant being sold.
     * @param amount The total amount to be paid.
     */
    void processSale(const string &plantName, double amount);

    /**
     * @brief Sets the payment strategy for this cashier.
     * @param strategy Unique pointer to the PaymentStrategy.
     */
    void setPaymentStrategy(PaymentStrategy *strategy);

    /**
     * @brief Gets the current payment method name.
     * @return Name of the current payment method.
     */
    string getPaymentMethod() const;

    /**
     * @brief Updates the cashier when a plant's state changes.
     * @param plant Pointer to the NurseryPlant that changed state.
     */
    void update(NurseryPlant *plant) override;
};

#endif // CASHIER_H