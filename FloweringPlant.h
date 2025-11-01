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
  string color;

public:
  /**
   * @brief Virtual destructor.
   */
  virtual ~FloweringPlant() {}

  /**
   * @brief Constructor.
   */
  FloweringPlant(const string &name, const string &maintenanceType, const string &color, double);

  /**
   * @brief getter for the color of the flowering plant.
   * @return The colour of the flowering plant.
   */
  string getColor() const;
};

#endif
