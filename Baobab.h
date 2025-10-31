/**
 * @file Baobab.h
 * @author Tafadzwa Musiiwa
 * @brief Concrete class representing a Baobab tree.
 */

#ifndef BAOBAB_H
#define BAOBAB_H

#include "Tree.h"
#include <string>

/**
 * @class Baobab
 * @brief Represents a Baobab tree, known for its massive trunk.
 */
class Baobab : public Tree, public NurseryPlant
{

public:
    /**
     * @brief Constructs a Baobab with a given age.
     * 
     */
    Baobab(double height, double price);

    /**
     * @brief Default constructor for Baobab tree
     */
    Baobab();

    /**
     * @brief Destructor.
     */
    ~Baobab() {}

    /**
     * @brief Display the information of the Baobab tree ( its height).
     */
    void displayInfo() const override;

        /**
     * @brief Gets the description of the Baobab tree
     * @return String describing the Baobab tree
     */
    virtual std::string getDescription() override;
    
    /**
     * @brief Calculates the cost of the Baobab tree
     * @return The price of the Baobab tree as a double
     */
    virtual double calculateCost() override;

    
};

#endif // BAOBAB_H
