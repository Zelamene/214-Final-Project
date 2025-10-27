#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Participant.h"
#include <string>

/**
 * @class Customer
 * @brief Represents a customer in the plant nursery system
 * 
 * This class handles customer interactions including browsing plants,
 * requesting information, making purchases, and seeking assistance.
 */
class Customer : public Participant {
public:
    /**
     * @brief Constructor for Customer
     * @param name The name of the customer
     * @param med Pointer to the nursery mediator (optional)
     */
    Customer(const std::string& name, NurseryMediator* med = nullptr);
    
    /**
     * @brief Customer browses available plants in the nursery
     */
    void browsePlants();
    
    /**
     * @brief Customer requests information about a specific plant type
     * @param plantType The type of plant to get information about
     */
    void requestPlantInfo(const std::string& plantType);
    
    /**
     * @brief Customer makes a purchase of a specific plant
     * @param plantName The name of the plant to purchase
     * @param price The price of the plant being purchased
     */
    void makePurchase(const std::string& plantName, double price);
    
    /**
     * @brief Customer requests assistance from staff
     */
    void askForAssistance();
    
    /**
     * @brief Customer views available plants in inventory
     */
    void viewAvailablePlants();
};

#endif // CUSTOMER_H