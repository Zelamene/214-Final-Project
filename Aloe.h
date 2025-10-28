/**
 * @file Aloe.h
 * @author Tafadzwa Musiiwa
 * @brief Concrete class representing an Aloe tree.
 */

#ifndef ALOE_H
#define ALOE_H

#include "NurseryPlant.h"
#include "Tree.h"
#include <string>

/**
 * @class Aloe
 * @brief Represents an Aloe, a tree known for its medicinal properties.
 */
class Aloe : public Tree, public NurseryPlant
{


public:
    /**
     * @brief Constructs an Aloe tree with a given height.
     * 
     */
    Aloe(double height, double price);

    /**
     * @brief Default constructor for Aloe plant
     */
    Aloe();

    /**
     * @brief Destructor.
     */
    ~Aloe() {}
    /**
     * @brief Displaying the information of the Aloe plant (i.e its height)
     */
    void displayInfo() const override;

    /**
     * @brief Gets the description of the Aloe plant
     * @return String describing the Aloe plant
     */
    virtual std::string getDescription() const override;
    
    /**
     * @brief Calculates the cost of the Aloe plant
     * @return The price of the Aloe plant as a double
     */
    virtual double calculateCost() override;
};

#endif
