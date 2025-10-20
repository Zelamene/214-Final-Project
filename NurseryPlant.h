/**
 * @file NurseryPlant.h
 * @author Tafadzwa Musiiwa
 * @brief Abstract base class representing a general nursery plant.
 */

#ifndef NURSERYPLANT_H
#define NURSERYPLANT_H
#include <string>

/**
 * @class NurseryPlant
 * @brief Abstract representation of a plant in the nursery.
 *
 * Serves as the base class for all plant types such as FloweringPlant and Tree.
 */
class NurseryPlant
{
protected:
   std::string name;
   std::string maintenanceType;
public:
    /**
     * @brief Virtual destructor for safe polymorphic deletion.
     */
    virtual ~NurseryPlant() {}
     /**
     * @brief Constructor
     */
    NurseryPlant(const std::string& name, const std::string& maintenanceType);

    /**
     * @brief getter for the name of the plant (e.g rose,baobab etc).
     */
    std::string getName() const;

    /**
     * @brief getter for the maintenance Type of the plant.
     */
    std::string getMaintenanceType() const;

    /**
     * @brief Display information about the plant.
     */
    virtual void displayInfo() const = 0;
};

#endif