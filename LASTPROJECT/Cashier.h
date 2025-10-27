#ifndef CASHIER_H
#define CASHIER_H

#include "Staff.h"
#include <string>

/**
 * @class Cashier
 * @brief Represents a cashier staff member in the nursery
 * 
 * This class handles all financial transactions and customer payments
 * in the plant nursery system, implementing the Staff interface.
 */
class Cashier : public Staff {
public:
    /**
     * @brief Constructor for Cashier staff member
     * @param name The name of the cashier
     * @param med Pointer to the nursery mediator (optional)
     */
    Cashier(const std::string& name, NurseryMediator* med = nullptr);
    
    /**
     * @brief Processes a customer payment
     * @param customerName Name of the customer making payment
     * @param amount The amount to be paid
     */
    void processPayment(const std::string& customerName, double amount);
    
    /**
     * @brief Confirms a plant sale transaction
     * @param plantName The name of the plant being sold
     */
    void confirmSale(const std::string& plantName);
    
    /**
     * @brief Requests a stock check for a specific plant
     * @param plantName The name of the plant to check
     */
    void requestStockCheck(const std::string& plantName);
    
    /**
     * @brief Issues a receipt to a customer
     * @param customerName Name of the customer receiving receipt
     */
    void issueReceipt(const std::string& customerName);
    
    /**
     * @brief Performs cashier-specific duties
     * 
     * Implements the abstract method from Staff class to
     * define cashier-specific responsibilities.
     */
    void performDuty() override;
};

#endif // CASHIER_H