/**
 * @file LowMaintenancePlantFactory.h
 * @author Tafadzwa Musiiwa
 * @brief Factory for creating low-maintenance plant types.
 */

#ifndef LOWMAINTENANCEPLANTFACTORY_H
#define LOWMAINTENANCEPLANTFACTORY_H

#include "PlantFactory.h"
#include "FloweringPlant.h"
#include "Tree.h"

/**
 * @class LowMaintenancePlantFactory
 * @brief Concrete factory that creates low-maintenance plants.
 *
 * Implements creation methods for plants that require minimal upkeep.
 */
class LowMaintenancePlantFactory : public PlantFactory
{
public:

    FloweringPlant* createFloweringPlant();

    Tree* createTree();
};

#endif // LOWMAINTENANCEPLANTFACTORY_H
