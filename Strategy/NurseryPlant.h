#ifndef NURSERYPLANT_H
#define NURSERYPLANT_H

#include <string>
#include <vector>
#include "Staff.h"

/**
 * @brief Abstract base class representing a plant in the nursery
 * 
 * This class serves as the base for all plant types in the nursery system,
 * providing common properties and operations for all plants.
 */
class NurseryPlant {
protected:
    std::string name;           ///< Name of the plant
    std::string state;          ///< Current state/growth stage of the plant
    double price;               ///< Price of the plant
    std::vector<Staff*> staffList; ///< List of staff members caring for this plant

public:
    /**
     * @brief Construct a new Nursery Plant object
     * @param n Name of the plant
     * @param p Price of the plant
     */
    NurseryPlant(std::string n, double p) : name(n), state("new"), price(p) {}

    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~NurseryPlant() = default;

    /**
     * @brief Get the plant's name
     * @return std::string The plant name
     */
    std::string getName() { return name; }

    /**
     * @brief Get the plant's price
     * @return double The plant price
     */
    double getPrice() { return price; }

    /**
     * @brief Set the plant's price
     * @param p New price value
     */
    void setPrice(double p) { price = p; }

    /**
     * @brief Set the plant's state
     * @param s New state value
     */
    void setState(std::string s) { state = s; }

    /**
     * @brief Get the plant's current state
     * @return std::string The current state
     */
    std::string getState() const { return state; }

    /**
     * @brief Add a staff member to the plant's care team
     * @param s Pointer to Staff member
     */
    void addStaff(Staff* s) { staffList.push_back(s); }

    /**
     * @brief Display all staff members caring for this plant
     */
    void showStaff() const {
        std::cout << "Staff caring for " << name << ": ";
        for (auto s : staffList)
            std::cout << s->getName() << " ";
        std::cout << "\n";
    }

    /**
     * @brief Prepare the plant for sale or display
     */
    void prepare() { std::cout << name << " is being prepared...\n"; }

    /**
     * @brief Get the type of plant (pure virtual)
     * @return std::string The plant type
     */
    virtual std::string getType() const = 0;
};

#endif