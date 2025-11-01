/**
 * @file PlantFactory.h
 * @author Tafadzwa Musiiwa
 * @brief Abstract interface for creating different types of plants
 */

#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "FloweringPlant.h"
#include "Tree.h"
using namespace std;

/**
 * @class PlantFactory
 * @brief Abstract factory for creating plant objects.
 *
 * Defines the interface for factories that can create different categories of plants,
 * such as flowering plants and trees
 */

class PlantFactory
{
public:
  /**
   * @brief Default constructor
   */
  PlantFactory() = default;
  /**
   * @brief Virtual destructor
   */
  virtual ~PlantFactory() {};

  /**
   * @brief Creates a FloweringPlant object.
   *
   * @param price Price of the flowering plant.
   * @param color Color of the flowering plant.
   * @return Pointer to a newly created FloweringPlant.
   */
  virtual FloweringPlant *createFloweringPlant(double price, string color) = 0;

  /**
   * @brief Creates a Tree object.
   *
   * @param height Height of the tree.
   * @param price Price of the tree.
   * @return Pointer to a newly created Tree.
   */
  virtual Tree *createTree(double height, double price) = 0;
};
#endif