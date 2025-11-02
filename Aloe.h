/**
 * @file Aloe.h
 * @author Tafadzwa Musiiwa
 * @brief Concrete class representing an Aloe tree.
 */

#ifndef ALOE_H
#define ALOE_H

#include "Tree.h"
#include <string>
using namespace std;
/**
 * @class Aloe
 * @brief Represents an Aloe, a tree known for its medicinal properties.
 */
class Aloe : public Tree
{

public:
    /**
     * @brief Constructs an Aloe tree with a given height.
     * @param height Height of the Aloe tree in meters.
     * @param price Price of the Aloe tree.
     *
     */
    Aloe(double height, double price);

    /**
     * @brief Destructor.
     */
    ~Aloe() {}
    /**
     * @brief Displaying the information of the Aloe plant (i.e its height)
     */
    void displayInfo() const override;
};

#endif