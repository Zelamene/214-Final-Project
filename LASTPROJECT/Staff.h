#ifndef STAFF_H
#define STAFF_H

#include "Participant.h"
#include <string>

/**
 * @class Staff
 * @brief Abstract base class for all staff members in the nursery
 * 
 * This class provides common functionality for all staff roles
 * and defines the interface for staff-specific duties.
 */
class Staff : public Participant {
protected:
    std::string role;  ///< The role/job title of the staff member
    
public:
    /**
     * @brief Constructor for Staff member
     * @param name The name of the staff member
     * @param role The role/job title of the staff member
     * @param med Pointer to the nursery mediator (optional)
     */
    Staff(const std::string& name, const std::string& role, NurseryMediator* med = nullptr);
    
    /**
     * @brief Gets the role of the staff member
     * @return The staff member's role as string
     */
    std::string getRole() const;
    
    /**
     * @brief Pure virtual method for performing staff-specific duties
     * 
     * This method must be implemented by all concrete staff classes
     * to define their specific responsibilities.
     */
    virtual void performDuty() = 0;
};

#endif // STAFF_H