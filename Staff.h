
/**
 * @file Staff.h
 * @brief Header file for the Staff class, implementing the Observer pattern.
 */

#ifndef STAFF_H
#define STAFF_H

#include "Observer.h"
#include <string>
#include "Inventory.h"
#include "Participant.h"

using namespace std;

class NurseryPlant;

/**
 * @brief Represents a staff member who observes plant state changes and manages inventory.
 *
 * The Staff class implements the Observer interface to be notified when a plant's state changes.
 * When a plant reaches the Mature state, the staff adds it to the inventory.
 */
class Staff : public Observer, public Participant {
private:
    Inventory* inventory;

protected:
    std::string role;  ///< The role/job title of the staff member

public:
    /**
     * @brief Constructs a Staff object with a reference to the inventory.
     * @param inventory Pointer to the Inventory object.
     */
    Staff(Inventory* inventory);

        /**
     * @brief Constructor for Staff member
     * @param name The name of the staff member
     * @param role The role/job title of the staff member
     * @param med Pointer to the nursery mediator (optional)
     */
    Staff(const std::string& name, const std::string& role, NurseryMediator* med = nullptr);

    /**
     * @brief Default destructor.
     */

    virtual ~Staff(); 


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

        /**
     * @brief Gets the role of the staff member
     * @return The staff member's role as string
     */
    std::string getRole() const;

        /**
     * @brief Pure virtual method for performing staff-specific duties
     * 
     * This method must be implemented by all concrete staff classes
     * to define their specific responsibilities.
     */
    virtual void performDuty() = 0;
};

#endif //Staff_H
