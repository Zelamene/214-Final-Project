#ifndef PLANTEXPERT_H
#define PLANTEXPERT_H

#include "Staff.h"
#include <string>

/**
 * @class PlantExpert
 * @brief Represents a plant expert staff member in the nursery
 * 
 * This class handles expert plant consultations, diagnoses, recommendations,
 * and educational activities for customers.
 */
class PlantExpert : public Staff {
public:
    /**
     * @brief Constructor for PlantExpert staff member
     * @param name The name of the plant expert
     * @param med Pointer to the nursery mediator (optional)
     */
    PlantExpert(const std::string& name, NurseryMediator* med = nullptr);
    
    /**
     * @brief Provides care advice for specific plant types
     * @param plantType The type of plant for care advice
     */
    void provideCareAdvice(const std::string& plantType);
    
    /**
     * @brief Diagnoses plant problems based on symptoms
     * @param symptoms The symptoms observed in the plant
     */
    void diagnosePlantProblem(const std::string& symptoms);
    
    /**
     * @brief Recommends plants suitable for specific conditions
     * @param conditions The environmental/growing conditions
     */
    void recommendPlants(const std::string& conditions);
    
    /**
     * @brief Performs expert consultation and education duties
     * 
     * Implements the abstract method from Staff class to
     * define plant expert responsibilities.
     */
    void performDuty() override;
};

#endif // PLANTEXPERT_H