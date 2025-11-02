#ifndef CONCRETENURSERYMEDIATOR_H
#define CONCRETENURSERYMEDIATOR_H

#include "NurseryMediator.h"
#include "Customer.h"
#include "Cashier.h"
#include "PlantExpert.h"
#include "Nurse.h"
#include "Inventory.h"
#include "Invoker.h"
#include "MessageSender.h"
#include "PrepareCommand.h"
#include "PackageOrderCommand.h"
#include "DeliverOrderCommand.h"
#include <vector>
using namespace std;

/**
 * @class ConcreteNurseryMediator
 * @brief Concrete implementation of the nursery mediator
 *
 * This class coordinates communication between all participants in the
 * nursery system (customers, staff, inventory) using the Mediator pattern.
 * It handles message routing and ensures loose coupling between components.
 */
class ConcreteNurseryMediator : public NurseryMediator
{
private:
    vector<Customer *> customers; /// List of registered customers
    vector<Staff *> staffMembers; /// List of registered staff members
    Inventory *inventory;         /// Pointer to inventory system

public:
    /**
     * @brief Default constructor
     */
    ConcreteNurseryMediator();

    /**
     * @brief Destructor
     */
    virtual ~ConcreteNurseryMediator();

    /**
     * @brief Registers a customer with the mediator
     * @param customer Pointer to the customer to register
     */
    void addCustomer(Customer *customer);

    /**
     * @brief Registers a staff member with the mediator
     * @param staff Pointer to the staff member to register
     */
    void addStaff(Staff *staff);

    /**
     * @brief Sets the inventory system for the mediator
     * @param inv Pointer to the inventory system
     */
    void setInventory(Inventory *inv);

    /**
     * @brief Main mediator method that handles all communications
     * @param sender The participant sending the message
     * @param event The message/event being sent
     */
    void notify(MessageSender *sender, const string &event) override;

    /**
     * @brief Handles inventory events.
     * @param event Inventory event.
     */
    void onInventoryEvent(Inventory::InventoryEvent event);

private:
    /**
     * @brief Handles events from customer participants
     * @param customer The customer sending the event
     * @param event The event message
     */
    void handleCustomerEvent(MessageSender *customer, const string &event);

    /**
     * @brief Handles events from staff participants
     * @param staff The staff member sending the event
     * @param event The event message
     */
    void handleStaffEvent(MessageSender *staff, const string &event);

    /**
     * @brief Broadcasts a message to all registered customers
     * @param message The message to broadcast
     */
    void notifyCustomers(const string &message);

    /**
     * @brief Broadcasts a message to all registered staff members
     * @param message The message to broadcast
     */
    void notifyStaff(const string &message);

    /**
     * @brief Determines the type of participant for routing
     * @param sender The participant to identify
     * @return String representing the participant type
     */
    void handleDispute(const std::string &customerName, const std::string &issueDescription);

    /**
     * @brief Determines the type of participant for routing
     * @param sender The participant to identify
     */
    string getSenderType(MessageSender *sender);


    /**
     * @brief Processes a customer's order for a plant
     * @param customerPlant The plant being ordered
     * @param customer The customer placing the order
     */
    void processCustomerOrder(NurseryPlant *customerPlant, Customer *customer)
    {
        if (!customerPlant || !customer)
            return;

        std::cout << "Processing customer order for " << customer->getName()
                  << " - Plant: " << customerPlant->getName() << std::endl;

        // Set customer for the plant
        customerPlant->setCustomer(customer);

        // Create order commands
        PrepareCommand prepareCmd(customerPlant);
        prepareCmd.execute();
    }
};

#endif // CONCRETENURSERYMEDIATOR_H