#ifndef INVENTORY_H
#define INVENTORY_H

#include "NurseryPlant.h"
#include "MessageReceiver.h"
#include <map>
#include <vector>
#include <string>
#include <functional>
using namespace std;

/**
 * @class Inventory
 * @brief Manages nursery plants and tracks stock levels.
 *
 * Handles adding, removing, and checking plant stock.
 * Can notify listeners of inventory events such as low stock or restocking.
 */
class Inventory : public MessageReceiver
{
public:
    /**
     * @enum EventType
     * @brief Types of inventory events.
     */
    enum class EventType
    {
        StockLow,   /// Stock is below threshold
        OutOfStock, /// Stock is empty
        Restocked   /// Stock has been replenished
    };

    /**
     * @struct InventoryEvent
     * @brief Represents an inventory event.
     */
    struct InventoryEvent
    {
        EventType type;        /// Type of the event
        std::string plantName; /// Name of the plant
        int currentStock;      /// Current stock count
    };

private:
    std::map<std::string, std::vector<NurseryPlant *>> itemStock; /// Plant instances by name
    std::map<std::string, size_t> stockCounts;                    /// Count of plants per name
    std::function<void(InventoryEvent)> eventListener;            /// Callback for inventory events

public:
    /**
     * @brief Constructs an empty inventory.
     */
    Inventory();

    /**
     * @brief Destructor.
     */
    ~Inventory();

    /**
     * @brief Checks if the requested quantity of a plant is in stock.
     * @param plantName Name of the plant.
     * @param quantity Quantity to check.
     * @return true if enough stock exists, false otherwise.
     */
    bool hasStock(const std::string &plantName, int quantity) const;

    /**
     * @brief Adds a plant to the inventory.
     * @param plantName Name of the plant.
     * @param plant Pointer to the plant instance.
     */
    void addPlant(const std::string &plantName, NurseryPlant *plant);

    /**
     * @brief Removes a quantity of a plant from inventory.
     * @param plantName Name of the plant.
     * @param quantity Quantity to remove (default 1).
     */
    void removePlant(const std::string &plantName, int quantity = 1);

    /**
     * @brief Displays the current inventory and stock counts.
     */
    void displayInventory() const;

    /**
     * @brief Sets a callback for inventory events.
     * @param listener Function to call when an inventory event occurs.
     */
    void setEventListener(std::function<void(InventoryEvent)> listener);

    /**
     * @brief Receives messages (MessageReceiver interface).
     * @param message Message received.
     */
    void receive(const std::string &message) override;
};

#endif
