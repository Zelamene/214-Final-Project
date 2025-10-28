/**
 * @file Staff.h
 * @brief Defines the Staff class responsible for caring for nursery plants and executing commands.
 */

#ifndef STAFF
#define STAFF

#include <string>
#include <vector>
#include "Command.h"
#include "NurseryPlant.h"
#include "CareStrategy.h"

class NurseryPlant;
class CareStrategy;

/**
 * @class Staff
 * @brief Represents a staff member who can care for plants and execute commands.
 */
class Staff {
private:
    std::string name;           ///< Name of the staff member
    CareStrategy* strategy;     ///< Strategy used to care for plants

public:
    /**
     * @brief Constructs a Staff member with a name and optional care strategy.
     * @param n Name of the staff member
     * @param s Pointer to a CareStrategy (default is nullptr)
     */
    Staff(std::string n, CareStrategy* s = nullptr);

    /**
     * @brief Gets the name of the staff member.
     * @return Name of the staff member
     */

     virtual ~Staff();

    std::string getName();

    /**
     * @brief Sets the care strategy for the staff member.
     * @param s Pointer to a CareStrategy
     */
    void setStrategy(CareStrategy* s);

    /**
     * @brief Performs care for a given nursery plant using the assigned strategy.
     * @param plant Reference to the NurseryPlant to be cared for
     */
    void careForPlant(NurseryPlant& plant);
    /**
     * @brief Executes a given command.
     * @param cmd Pointer to the Command to be executed
     */
    void perform(Command* cmd);
};

#endif
