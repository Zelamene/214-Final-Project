#ifndef NURSERYPLANT_H
#define NURSERYPLANT_H

#include "State.h"
#include "Subject.h"
#include "State.h"
#include "Subject.h"
#include "Order.h"
#include <vector>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/**
 * @file NurseryPlant.h
 * @brief Header file for the NurseryPlant class, representing a plant in the nursery system.
 */
/**
 * @file NurseryPlant.h
 * @brief Header file for the NurseryPlant class, representing a plant in the nursery system.
 */
/**
 * @class NurseryPlant
 * @brief Abstract representation of a plant in the nursery.
 *
 * Serves as the base class for all plant types such as FloweringPlant and Tree.
 * This class also functions as a leaf in the Composite design pattern,
 * implementing the abstract methods from the Order base class.
 * @brief Represents a nursery plant with state management and observer pattern support.
 *
 * The NurseryPlant class implements the Subject interface to allow observers (like Staff)
 * to be notified of state changes. It uses the State pattern to manage different growth stages.
 * @brief Represents a nursery plant with state management and observer pattern support.
 *
 * The NurseryPlant class implements the Subject interface to allow observers (like Staff)
 * to be notified of state changes. It uses the State pattern to manage different growth stages.
 */

class NurseryPlant : public Subject ,public Order{
    protected:
    string name;
    string maintenanceType;
    int waterlevel;
    string GREEN  = "\033[1;32m";
    string YELLOW = "\033[1;33m";
    string RED    = "\033[1;31m";
    string RESET  = "\033[0m";
    std::string description;  ///< Description of the plant
    double basePrice;        ///< Base price of the plant without decorations
    
private:
    State* currentState; /**< Pointer to the current state of the plant. */
    std::vector<Observer*> observers; /**< List of observers attached to this plant. */

public:

    /**
     * @brief Destructor for NurseryPlant.
     * @brief Constructs a NurseryPlant with an initial state and name.
     * @param initialState Pointer to the initial state object.
     * @param name The name of the plant.
     */
    NurseryPlant(const string &name, const string &maintenanceType, double price);

    NurseryPlant();

    std::string planCurrentState() const;

    /**
     * @brief Gets the name of the plant.
     * @return The name of the plant as a string.
     */

    /**
     * @brief Sets a new state for the plant and notifies observers.
     * @param newState Pointer to the new state object.
     */
    void setState(State* newState);

    /**
     * @brief Starts the growing process by transitioning through states until mature.
     */
    void startGrowing();

    string getName() const;
    int getWaterLevel();
  
    void pourWater(int liters);

    /**
     * @brief Gets the name of the current state.
     * @return The name of the current state as a string.
     */
    std::string getStateName() const;
    void setWaterlevel(int number);

    /**
     * @brief Attaches an observer to this plant.
     * @param observer Pointer to the observer to attach.
     */
    void attach(Observer* observer) override;

    /**
     * @brief Detaches an observer from this plant.
     * @param observer Pointer to the observer to detach.
     */
    void detach(Observer* observer) override;

    /**
     * @brief Notifies all attached observers of a state change.

    
    string getName() const;

    /**
     * @brief getter for the maintenance Type of the plant.
     */
    void notify() override;
    string getMaintenanceType() const;

    /**
     * @brief Display information about the plant.
     */
    virtual void displayInfo() const;


    /**
     * @copydoc Order::getTotal()
     * @override
     */
    double getTotal() override;

    /**
     * @copydoc Order::displayDetails()
     * @override
     */
    void displayDetails() override;

    /**
     * @copydoc Order::calculateTax()
     * @override
     */
    void calculateTax() override;

    /**
     * @brief Creates and returns a clone of this object.
     * @return Pointer to a new NurseryPlant object (deep copy).
     */
    Order *clone() const override;

        /**
     * @brief Gets the description of the plant
     * @return String describing the plant
     */
    virtual std::string getDescription() = 0;
    
    /**
     * @brief Calculates the cost of the plant
     * @return The price of the plant as a double
     */
    virtual double calculateCost() = 0;
    
    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     */
    virtual ~NurseryPlant() noexcept override;
};

#endif //NurseryPlant