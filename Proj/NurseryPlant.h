/**
 * @file NurseryPlant.h
 * @brief Abstract base class for nursery plants.
 */

#ifndef NURSERYPLANT_H
#define NURSERYPLANT_H

#include <string>
#include <vector>
#include "Staff.h"

/**
 * @class NurseryPlant
 * @brief Represents a plant in the nursery.
 */
class Staff;
class NurseryPlant {
protected:
    std::string name; ///< Name of the plant
    std::string state; ///< Current state of the plant
    double price; ///< Price of the plant
    std::vector<Staff*> staffList; ///< Staff assigned to the plant

public:
    /**
     * @brief Constructs a plant with name and price.
     * @param n Name of the plant
     * @param p Price of the plant
     */
     NurseryPlant(std::string n, double p);
    virtual ~NurseryPlant();

    /**
     * @brief Gets the name of the plant.
     * @return Type as a string
     */
    std::string getName();
    /**
     * @brief Gets the price value of the plant.
     * @return Type as a double
     */

    double getPrice();
    /**
     * @brief Sets the price value of the plant.
     * @param p Value of the new price
     */

    void setPrice(double p);
    /**
     * @brief Sets the new state of the plant.
     * @param s Value of the state
     */

    void setState(std::string s);
    /**
     * @brief Gets the type of the plant.
     * @return Type as a string
     */

    std::string getState();

    /**
     * @brief Adds a staff member to the plant.
     * @param s Pointer to the staff
     */
    void addStaff(Staff* s) ;

    /**
     * @brief Displays staff assigned to the plant.
     */
    void showStaff() const;

    /**
     * @brief Prepares the plant.
     */
    void prepare();

    /**
     * @brief Gets the type of the plant.
     * @return Type as a string
     */
    virtual std::string getType() const = 0;
};

#endif
