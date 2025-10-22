/**
 * @file Staff.h
 * @brief Header file for the Staff class, implementing the Observer pattern.
 */

#ifndef STAFF_H
#define STAFF_H

#include "Observer.h"
#include <string>
#include "Inventory.h"

class NurseryPlant;

/**
 * @brief Represents a staff member who observes plant state changes and manages inventory.
 *
 * The Staff class implements the Observer interface to be notified when a plant's state changes.
 * When a plant reaches the Mature state, the staff adds it to the inventory.
 */
class Staff : public Observer {
private:
    Inventory* inventory;

public:
    /**
     * @brief Constructs a Staff object with a reference to the inventory.
     * @param inventory Pointer to the Inventory object.
     */
    Staff(Inventory* inventory);

    /**
     * @brief Default destructor.
     */
    virtual ~Staff() = 0; 

    /**
     * @brief Updates the staff when a plant's state changes.
     * @param plant Pointer to the NurseryPlant that changed state.
     */
    void update(NurseryPlant* plant) override;

    /**
     * @brief Gets the name of the staff member.
     * @return A string representing the staff member's name.
     */
    std::string getName() const;
};

#endif
