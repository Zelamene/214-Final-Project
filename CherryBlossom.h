/**
 * @file CherryBlossom.h
 * @author Tafadzwa Musiiwa
 * @brief Concrete class representing a Cherry Blossom tree.
 */

#ifndef CHERRYBLOSSOM_H
#define CHERRYBLOSSOM_H

#include "FloweringPlant.h"
#include "NurseryPlant.h"
#include <string>

/**
 * @class CherryBlossom
 * @brief Represents a cherry blossom, a type of flowering plant.
 */
class CherryBlossom : public FloweringPlant, public NurseryPlant
{

public:
    /**
     * @brief Constructs a CherryBlossom with a given blooming season.
     * 
     */
    CherryBlossom(double price);

        /**
     * @brief Default constructor for Cherry Blossom tree
     */
    CherryBlossom();

    /**
     * @brief Destructor.
     */
    ~CherryBlossom() {}
    /**
     * @brief Display information about the CherryBlossom plant.
     */
    void displayInfo() const override;

     /**
     * @brief Gets the description of the Cherry Blossom tree
     * @return String describing the Cherry Blossom tree
     */
    virtual std::string getDescription() override;
    
    /**
     * @brief Calculates the cost of the Cherry Blossom tree
     * @return The price of the Cherry Blossom tree as a double
     */
    virtual double calculateCost() override;
};

#endif
