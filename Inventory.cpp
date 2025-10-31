#include "Inventory.h"
#include <iostream>

Inventory::Inventory() = default;

Inventory::~Inventory()
{
}

bool Inventory::hasStock(const std::string &plantName, int quantity) const
{
    auto it = stockCounts.find(plantName);
    return it != stockCounts.end() && it->second >= static_cast<size_t>(quantity);
}

void Inventory::addPlant(const std::string &plantName, NurseryPlant *plant)
{
    itemStock[plantName].push_back(plant);
    stockCounts[plantName]++;

    if (eventListener)
    {
        InventoryEvent event{EventType::Restocked, plantName, static_cast<int>(stockCounts[plantName])};
        eventListener(event);
    }
}

void Inventory::removePlant(const std::string &plantName, int quantity)
{
    auto it = itemStock.find(plantName);
    if (it != itemStock.end() && it->second.size() >= static_cast<size_t>(quantity))
    {
        for (int i = 0; i < quantity; ++i)
        {

            delete it->second.back();
            it->second.pop_back();
        }
        stockCounts[plantName] = it->second.size();
        if (it->second.empty())
        {
            itemStock.erase(it);
            stockCounts.erase(plantName);
        }

        // Check for stock events
        if (eventListener)
        {
            int currentStock = static_cast<int>(stockCounts[plantName]);
            if (currentStock == 0)
            {
                InventoryEvent event{EventType::OutOfStock, plantName, currentStock};
                eventListener(event);
            }
            else if (currentStock < 5)
            { // we assumes ta=hat 5 is the threshold for low stock
                InventoryEvent event{EventType::StockLow, plantName, currentStock};
                eventListener(event);
            }
        }
    }
}

void Inventory::displayInventory() const
{
    std::cout << "Inventory:\n";
    for (const auto &pair : stockCounts)
    {
        std::cout << "Item: " << pair.first << ", Stock: " << pair.second << "\n";
    }
}

void Inventory::setEventListener(std::function<void(InventoryEvent)> listener)
{
    eventListener = listener;
}

void Inventory::receive(const std::string &message)
{
    // for displaying

    std::cout << "Inventory received: " << message << std::endl;
}