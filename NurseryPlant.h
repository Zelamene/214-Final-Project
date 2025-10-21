#ifndef NURSERYPLANT_H
#define NURSERYPLANT_H

#include "State.h"
#include "Subject.h"
#include <vector>
#include <string>

/**
 * @file NurseryPlant.h
 * @brief Header file for the NurseryPlant class, representing a plant in the nursery system.
 */

/**
 * @brief Represents a nursery plant with state management and observer pattern support.
 *
 * The NurseryPlant class implements the Subject interface to allow observers (like Staff)
 * to be notified of state changes. It uses the State pattern to manage different growth stages.
 */
class NurseryPlant : public Subject {
private:
    State* currentState; /**< Pointer to the current state of the plant. */
    std::string name; /**< Name of the plant. */
    std::vector<Observer*> observers; /**< List of observers attached to this plant. */

public:
    /**
     * @brief Constructs a NurseryPlant with an initial state and name.
     * @param initialState Pointer to the initial state object.
     * @param name The name of the plant.
     */
    NurseryPlant(State* initialState, std::string name);

    /**
     * @brief Destructor for NurseryPlant.
     */
    ~NurseryPlant();

    /**
     * @brief Gets the name of the plant.
     * @return The name of the plant as a string.
     */
    std::string getName() const;

    /**
     * @brief Sets a new state for the plant and notifies observers.
     * @param newState Pointer to the new state object.
     */
    void setState(State* newState);

    /**
     * @brief Starts the growing process by transitioning through states until mature.
     */
    void startGrowing();

    /**
     * @brief Gets the name of the current state.
     * @return The name of the current state as a string.
     */
    std::string getStateName() const;

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
     */
    void notify() override;
};

#endif
