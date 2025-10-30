/**
 * @file HighMaintenancePlantFactory.h
 * @author Tafadzwa Musiiwa
 * @brief Factory for creating high-maintenance plant types.
 */

#ifndef HIGHMAINTENANCEPLANTFACTORY_H
#define HIGHMAINTENANCEPLANTFACTORY_H

#include "PlantFactory.h"
#include "FloweringPlant.h"
#include "Tree.h"
using namespace std;

/**
 * @class HighMaintenancePlantFactory
 * @brief Concrete factory that creates high-maintenance plants.
 *
 * Implements creation methods for flowering plants and trees
 * that require more care and attention.
 */
class HighMaintenancePlantFactory : public PlantFactory
{
public:
    /**
     * @brief Creates a high-maintenance flowering plant.
     *
     * @param price Price of the plant.
     * @param color Optional color of the plant (default is empty string).
     * @return Pointer to a newly created high-maintenance FloweringPlant.
     */
    FloweringPlant *createFloweringPlant(double price, string color = "") override;

    /**
     * @brief Creates a high-maintenance tree.
     * @return Pointer to a new high-maintenance Tree.
     */
    Tree *createTree(double height, double price) override;
};

#endif