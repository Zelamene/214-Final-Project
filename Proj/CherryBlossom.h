
#ifndef CHERRYBLOSSOM_H
#define CHERRYBLOSSOM_H

#include "NurseryPlant.h"
#include "FloweringPlant.h"
#include <string>

/**
 * @brief Concrete class representing a Cherry Blossom plant
 * 
 * Cherry Blossom is a specific type of Flowering Plant with its own
 * state management and characteristics.
 */
class CherryBlossom : public FloweringPlant {


public:
    /**
     * @brief Construct a new Cherry Blossom object
     * @param price Initial price, defaults to 40.0
     */
    CherryBlossom(double price = 40.0);
};

#endif