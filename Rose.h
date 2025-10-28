/**
 * @file Rose.h
 * @author Tafadzwa Musiiwa
 * @brief Concrete class representing a Rose plant.
 */

#ifndef ROSE_H
#define ROSE_H

#include "FloweringPlant.h"
#include "NurseryPlant.h"
#include <string>

/**
 * @class Rose
 * @brief Represents a rose, a type of flowering plant.
 */
class Rose : public FloweringPlant, public NurseryPlant
{


public:
    /**
     * @brief Constructs a Rose with a given colour.
     * 
     */
    Rose(const std::string& color, double price);

    /**
     * @brief Gets the description of the Rose plant
     * @return String describing the Rose plant
     */
    virtual std::string getDescription() override;

        /**
     * @brief Calculates the cost of the Rose plant
     * @return The price of the Rose plant as a double
     */
    virtual double calculateCost() override;

    /**
     * @brief Destructor.
     */
    ~Rose() {}
    /**
     * @brief Display information about a Rose.
     */

    void displayInfo() const override;
};

#endif //Rose_H
