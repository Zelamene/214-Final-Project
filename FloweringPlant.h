/**
 * @file FloweringPlant.h
 * @author Tafadzwa Musiiwa
 * @brief Abstract class representing flowering plants.
 */

#ifndef FLOWERINGPLANT_H
#define FLOWERINGPLANT_H

#include "NurseryPlant.h"

/**
 * @class FloweringPlant
 * @brief Abstract class for plants that produce flowers.
 *
 * Serves as a base for specific flowering plant types like Rose and CherryBlossom.
 */
class FloweringPlant : public NurseryPlant
{
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~FloweringPlant() {}
};

#endif 
