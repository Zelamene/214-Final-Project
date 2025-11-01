#include "ConcreteNurseryMediator.h"
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

    std::cout << "From: " << dynamic_cast<Customer *>(sender)->getName() << std::endl;

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
            inventory->removePlant(plantName, 1);
            customer1->receive("✅ Purchase successful: " + plantName + ". Please proceed to checkout.");
            std::cout << "Sale completed: " << plantName << " to " << customerName << "\n";
        }
        else
        {
            customer1->receive("❌ Sorry, " + plantName + " is out of stock.");
            if (inventory)
                customer1->receive("Would you like to be notified when it's restocked?");
        }
        return;
    }

    //  INFORMATION REQUEST 
    if (event.find("wants information about") != std::string::npos)
    {
        std::cout << "Forwarding information request...\n";
        notifyStaff(customerName + " requested plant info: " + event);
        std::string topic = event.substr(event.find("about") + 6);
        customer1->receive("Our expert will assist you with information about " + topic + ".");
        return;
    }

    //  ASSISTANCE REQUEST 
    if (event.find("needs assistance") != std::string::npos)
    {
        std::cout << "Assistance requested by " << customerName << "\n";
        notifyStaff("🔔 Assistance needed: " + customerName + " at sales floor.");
        customer1->receive("A staff member will assist you shortly.");
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
        return;
    }

    if (event.find("looking for") != std::string::npos || event.find("question about") != std::string::npos)
    {
        notifyStaff("Customer inquiry: " + customerName + " - " + event);
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