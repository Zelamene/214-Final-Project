#ifndef NURSE_H
#define NURSE_H

#include "Staff.h"
#include <string>

/**
 * @class Nurse
 * @brief Represents a plant nurse staff member in the nursery
 * 
 * This class handles plant care and maintenance activities including
 * watering, fertilizing, pruning, and treating sick plants.
 */
class Nurse : public Staff {
public:
    /**
     * @brief Constructor for Nurse staff member
     * @param name The name of the nurse
     * @param med Pointer to the nursery mediator (optional)
     */
    Nurse(const std::string& name, NurseryMediator* med = nullptr);
    
    /**
     * @brief Waters plants according to their specific needs
     */
    void waterPlants();
    
    /**
     * @brief Applies fertilizer to plants that need nutrients
     */
    void fertilizePlants();
    
    
    /**
     * @brief Monitors plant health and checks for issues
     */
    void monitorPlantHealth();
    
    
    /**
     * @brief Performs nurse-specific plant care duties
     * 
     * Implements the abstract method from Staff class to
     * define plant nursing responsibilities.
     */
    void performDuty() override;
};

#endif // NURSE_H