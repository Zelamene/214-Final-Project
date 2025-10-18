/**
 * @file NurseryPlant.h
 * @author Tafadzwa Musiiwa
 * @brief Abstract base class representing a general nursery plant.
 */

#ifndef NURSERYPLANT_H
#define NURSERYPLANT_H

/**
 * @class NurseryPlant
 * @brief Abstract representation of a plant in the nursery.
 *
 * Serves as the base class for all plant types such as FloweringPlant and Tree.
 */
class NurseryPlant
{
public:
    /**
     * @brief Virtual destructor for safe polymorphic deletion.
     */
    virtual ~NurseryPlant() {}
};

#endif