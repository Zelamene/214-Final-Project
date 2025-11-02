#include "ConcreteNurseryMediator.h"
#include "CashierHandler.h"
#include "Issue.h"
#include "ManagerHandler.h"
#include "PlantExpert.h"
#include <iostream>

ConcreteNurseryMediator::ConcreteNurseryMediator() : inventory(nullptr) {};

ConcreteNurseryMediator::~ConcreteNurseryMediator() {};

void ConcreteNurseryMediator::addCustomer(Customer *customer)
{
    customer->setMediator(this);
    customers.push_back(customer);
};

void ConcreteNurseryMediator::addStaff(Staff *staff)
{
    staff->setMediator(this);
    staffMembers.push_back(staff);
};

void ConcreteNurseryMediator::setInventory(Inventory *inv)
{
    inventory = inv;
    if (inventory)
    {
        // Set the event listener for the inventory
        inventory->setEventListener([this](Inventory::InventoryEvent event)
                                    { this->onInventoryEvent(event); });
    }
};

void ConcreteNurseryMediator::notify(MessageSender *sender, const std::string &event)
{
    std::string senderName = "Unknown";
    std::string senderType = "Unknown";

    // Safely get sender name without assuming type
    if (auto *customer = dynamic_cast<Customer *>(sender))
    {
        senderName = customer->getName();
        senderType = "Customer";
    }
    else if (auto *staff = dynamic_cast<Staff *>(sender))
    {
        senderName = staff->getName();
        senderType = "Staff";
    }
    else if (auto *inventory = dynamic_cast<Inventory *>(sender))
    {
        senderName = "Inventory";
        senderType = "Inventory";
    }

    std::cout << "From: " << senderName << " (" << senderType << ")" << std::endl;
    std::cout << "Event: " << event << std::endl;
    std::cout << "Action: ";

    // Route based on sender type
    if (dynamic_cast<Customer *>(sender))
    {
        handleCustomerEvent(sender, event);
    }
    else if (dynamic_cast<Staff *>(sender))
    {
        handleStaffEvent(sender, event);
    }
    else if (dynamic_cast<Inventory *>(sender))
    {
        // Handle inventory events if needed
        std::cout << "Inventory system event" << std::endl;
    }
}

void ConcreteNurseryMediator::onInventoryEvent(Inventory::InventoryEvent event)
{
    switch (event.type)
    {
    case Inventory::EventType::StockLow:
        notifyStaff("Inventory: " + event.plantName + " is running low. Current stock: " + std::to_string(event.currentStock));
        break;
    case Inventory::EventType::OutOfStock:
        notifyStaff("Inventory: " + event.plantName + " is out of stock!");
        break;
    case Inventory::EventType::Restocked:
        notifyStaff("Inventory: " + event.plantName + " has been restocked to " + std::to_string(event.currentStock));
        break;
    };
}
void ConcreteNurseryMediator::handleCustomerEvent(MessageSender *customer, const std::string &event)
{
    if (!customer)
    {
        std::cout << "[Warning] Null customer event received.\n";
        return;
    }
    Customer *customer1 = dynamic_cast<Customer *>(customer);

    std::string customerName = customer1->getName();
    std::cout << "Handling event from customer: " << customerName << "\n";

    //  PURCHASE REQUEST

    if (event.find("wants to purchase") != std::string::npos)
    {
        std::cout << "Processing purchase request...\n";

        size_t pos = event.find("purchase");
        std::string plantName = (pos != std::string::npos) ? event.substr(pos + 9) : "";
        size_t endPos = plantName.find(" for");
        if (endPos != std::string::npos)
            plantName = plantName.substr(0, endPos);

        plantName.erase(0, plantName.find_first_not_of(" \t"));
        plantName.erase(plantName.find_last_not_of(" \t") + 1);

        if (plantName.empty())
        {
            customer1->receive("Please specify which plant you want to purchase.");
            return;
        }

        if (inventory && inventory->hasStock(plantName, 1))
        {
            notifyStaff(customerName + " wants to purchase " + plantName);

            // Get the actual plant from inventory
            NurseryPlant *customerPlant = inventory->getPlantForSale(plantName);

            if (customerPlant)
            {
                customer1->receive("📋 Order received for " + plantName + ". Processing your order...");

                // Process the order with the inventory plant
                processCustomerOrder(customerPlant, customer1);
            }
            else
            {
                customer1->receive("❌ Sorry, there was an error processing your purchase.");
            }
        }
        else
        {
            customer1->receive("❌ Sorry, " + plantName + " is out of stock.");
            return;
        }
        return;
    } //  INFORMATION REQUEST
    if (event.find("wants information about") != std::string::npos)
    {
        std::cout << "Forwarding information request...\n";
        notifyStaff(customerName + " requested plant info: " + event);
        std::string topic = event.substr(event.find("about") + 6);
        customer1->receive("Our expert will assist you with information about " + topic + ".");
        PlantExpert::giveAdvice();
        return;
    }

       //  CHECKOUT
    if (event.find("checkout") != std::string::npos)
    {
        std::cout << customerName << " proceeding to checkout.\n";
        notifyStaff("💰 Checkout: " + customerName + " is ready at register.");
        customer1->receive("Please proceed to the cashier for payment.");
        return;
    }

    //  REFUND OR RETURN
    if (event.find("refund") != std::string::npos || event.find("return") != std::string::npos)
    {
        std::cout << "Refund/return request from " << customerName << "\n";
        notifyStaff("🔄 Refund/Return request: " + customerName + " - " + event);
        customer1->receive("Please bring your receipt to the service desk for assistance.");
        return;
    }

    //  COMPLAINT
    if (event.find("complaint") != std::string::npos)
    {
        std::cout << "Complaint received from " << customerName << "\n";
        notifyStaff("⚠️ Complaint: " + customerName + " - " + event);
        customer1->receive("We’re sorry for the inconvenience. A manager will contact you soon.");
        return;
    }

    //  GENERAL ACTIVITY
    if (event.find("browsing") != std::string::npos)
    {
        std::cout << customerName << " is browsing.\n";
        if (inventory)
        {
            inventory->displayInventory();
        }
        return;
    }

    if (event.find("looking for") != std::string::npos || event.find("question about") != std::string::npos)
    {
        notifyStaff("Customer inquiry: " + customerName + " - " + event);
    }
    // SIMPLE DISPUTE HANDLING - Direct CoR integration
    if (event.find("unhappy") != std::string::npos ||
        event.find("Complaint") != std::string::npos ||
        event.find("not working") != std::string::npos)
    {

        std::string complaintDetails = event;
        if (event.find(":") != std::string::npos)
        {
            complaintDetails = event.substr(event.find(":") + 1);
        }

        handleDispute(customerName, complaintDetails);

        customer1->receive("We're addressing your concern immediately.");
        return;
    }
    else
    {
        std::cout << "General activity logged: " << event << "\n";
    }
}
void ConcreteNurseryMediator::handleStaffEvent(MessageSender *staff, const std::string &event)
{
    if (event == "restock")
    {
        if (inventory)
        {
            // default additon for now
            inventory->addPlant("Rose", new NurseryPlant("Rose", "High Maintenance", 45.0));
            notifyCustomers("New plants are now available! (Roses)");
        }
    }
    else
    {
        notifyCustomers("Staff update: " + event);
    }
}

void ConcreteNurseryMediator::notifyCustomers(const std::string &message)
{
    for (auto *customer : customers)
    {
        customer->receive(message);
    }
}

void ConcreteNurseryMediator::notifyStaff(const std::string &message)
{
    for (auto *staff : staffMembers)
    {
        staff->receive(message);
    }
};

void ConcreteNurseryMediator::handleDispute(const std::string &customerName, const std::string &issueDescription)
{

    Issue dispute("Escalated", "Dispute from " + customerName + ": " + issueDescription, nullptr);

    CashierHandler cashierHandler;
    ManagerHandler managerHandler;

    cashierHandler.setNext(&managerHandler);

    cashierHandler.handle(&dispute);
}

std::string ConcreteNurseryMediator::getSenderType(MessageSender *sender)
{
    if (dynamic_cast<Customer *>(sender))
        return "Customer";
    if (dynamic_cast<Staff *>(sender))
        return "Staff";
    if (dynamic_cast<Inventory *>(sender))
        return "Inventory";
    return "Unknown";
}