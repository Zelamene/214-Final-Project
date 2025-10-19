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
    NurseryPlant(std::string n, double p)
        : name(n), state("new"), price(p) {}

    virtual ~NurseryPlant() = default;

    std::string getName() { return name; }
    double getPrice() { return price; }
    void setPrice(double p) { price = p; }
    void setState(std::string s) { state = s; }
    std::string getState() const { return state; }

    /**
     * @brief Adds a staff member to the plant.
     * @param s Pointer to the staff
     */
    void addStaff(Staff* s) { staffList.push_back(s); }

    /**
     * @brief Displays staff assigned to the plant.
     */
    void showStaff() const;

    /**
     * @brief Prepares the plant.
     */
    void prepare() { std::cout << name << " is being prepared...\n"; }

    /**
     * @brief Gets the type of the plant.
     * @return Type as a string
     */
    virtual std::string getType() const = 0;
};

#endif
