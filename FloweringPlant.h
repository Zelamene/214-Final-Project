/**
 * @file FloweringPlant.h
 * @author Tafadzwa Musiiwa
 * @brief Abstract class representing flowering plants.
 */

#ifndef FLOWERINGPLANT_H
#define FLOWERINGPLANT_H

#include "NurseryPlant.h"
using namespace std;

/**
 * @class FloweringPlant
 * @brief Abstract class for plants that produce flowers.
 *
 * Serves as a base for specific flowering plant types like Rose and CherryBlossom.
 */
class FloweringPlant : public NurseryPlant
{
protected:
  // Color of the flowering plant
  string color;

public:
  /**
   * @brief Virtual destructor.
   */
  virtual ~FloweringPlant() {}

  /**
   * @brief Constructor.
   * @param name Name of the plant.
   * @param maintenanceType Maintenance type of the plant.
   * @param color Color of the flowers.
   * @param price Price of the plant.
   * 
   * 
   */
  FloweringPlant(const string &name, const string &maintenanceType, const string &color, double price);

  /**
   * @brief getter for the color of the flowering plant.
   * @return The colour of the flowering plant.
   */
  string getColor() const;
};

#endif
