/**
 * @file Customer.h
 * @brief Represents a customer placing an order.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "CommunicatingParticipant.h"
#include "NurseryMediator.h"
using namespace std;

/**
 * @class Customer
 * @brief Stores customer information.
 *
 * Inherits from CommunicatingParticipant to send and receive messages via the mediator.
 */
class Customer : public CommunicatingParticipant
{
private:
    string name; // Name of the customer
public:
    /**
     * @brief Constructs a Customer with a given name and optional mediator.
     * @param n Name of the customer
     * @param mediator Mediator for communication (default nullptr)
     */
    Customer(string n, NurseryMediator *mediator = nullptr);

    /**
     * @brief Gets the customer's name.
     * @return Name of the customer
     */
    string getName();

    /**
     * @brief Simulates browsing plants in the nursery.
     */
    void browsePlants();

    /**
     * @brief Requests advice about a specific plant type from staff.
     * @param plantType Type of plant to get advice about.
     */
    void requestAdvice(const std::string &plantType);

    /**
     * @brief Purchases a plant.
     * @param plantName Name of the plant to purchase.
     */
    void purchasePlant(const std::string &plantName);
};

#endif
