#ifndef CONCRETENURSERYMEDIATOR_H
#define CONCRETENURSERYMEDIATOR_H

#include "NurseryMediator.h"
#include "Customer.h"
#include "Cashier.h"
#include "PlantExpert.h"
#include "Nurse.h"
#include "Inventory.h"
#include <vector>

/**
 * @class ConcreteNurseryMediator
 * @brief Concrete implementation of the nursery mediator
 * 
 * This class coordinates communication between all participants in the
 * nursery system (customers, staff, inventory) using the Mediator pattern.
 * It handles message routing and ensures loose coupling between components.
 */
class ConcreteNurseryMediator : public NurseryMediator {
private:
    std::vector<Customer*> customers;      ///< List of registered customers
    std::vector<Staff*> staffMembers;      ///< List of registered staff members
    Inventory* inventory;                  ///< Pointer to inventory system
    
public:
    /**
     * @brief Default constructor
     */
    ConcreteNurseryMediator();
    
    /**
     * @brief Destructor
     */
    ~ConcreteNurseryMediator();
    
    /**
     * @brief Registers a customer with the mediator
     * @param customer Pointer to the customer to register
     */
    void addCustomer(Customer* customer);
    
    /**
     * @brief Registers a staff member with the mediator
     * @param staff Pointer to the staff member to register
     */
    void addStaff(Staff* staff);
    
    /**
     * @brief Sets the inventory system for the mediator
     * @param inv Pointer to the inventory system
     */
    void setInventory(Inventory* inv);
    
    /**
     * @brief Main mediator method that handles all communications
     * @param sender The participant sending the message
     * @param event The message/event being sent
     */
    void notify(Participant* sender, const std::string& event) override;

private:
    /**
     * @brief Handles events from customer participants
     * @param customer The customer sending the event
     * @param event The event message
     */
    void handleCustomerEvent(Participant* customer, const std::string& event);
    
    /**
     * @brief Handles events from staff participants
     * @param staff The staff member sending the event
     * @param event The event message
     */
    void handleStaffEvent(Participant* staff, const std::string& event);
    
    /**
     * @brief Handles events from inventory system
     * @param inventory The inventory system sending the event
     * @param event The event message
     */
    void handleInventoryEvent(Participant* inventory, const std::string& event);
    
    /**
     * @brief Broadcasts a message to all registered customers
     * @param message The message to broadcast
     */
    void notifyCustomers(const std::string& message);
    
    /**
     * @brief Broadcasts a message to all registered staff members
     * @param message The message to broadcast
     */
    void notifyStaff(const std::string& message);
    
    /**
     * @brief Determines the type of participant for routing
     * @param sender The participant to identify
     * @return String representing the participant type
     */
    std::string getSenderType(Participant* sender);
};

#endif // CONCRETENURSERYMEDIATOR_H