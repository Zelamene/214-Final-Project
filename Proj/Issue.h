#ifndef ISSUE_H
#define ISSUE_H
#include <string>

/**
 * @class Issue
 * @brief Represents a customer issue or ticket in the dispute handling system.
 *
 * Each Issue has an identifier, description, and a solved status.
 * Handlers in the chain use these attributes to determine who should handle the issue.
 */
class Issue
{
public:
    /**
     * @brief Constructs an Issue with the given parameters.
     * @param id Unique identifier for the issue (e.g., "Cashier" or "Manager").
     * @param description Textual description of the issue.
     * @param solved Boolean flag indicating whether the issue is solved.
     */
    Issue(std::string id, std::string description, bool solved);

    /**
     * @brief Destructor for the Issue class.
     */
    ~Issue();

    /**
     * @brief Gets the issue identifier.
     * @return The ID string.
     */
    std::string getId();

    /**
     * @brief Gets the issue description.
     * @return The description string.
     */
    std::string getDescription();

    /**
     * @brief Checks whether the issue has been solved.
     * @return True if solved, false otherwise.
     */
    bool getSolved();

    /**
     * @brief Sets the issue description.
     * @param description New description text.
     */
    void setDescription(std::string description);

    /**
     * @brief Sets the solved status.
     * @param solved True if solved, false otherwise.
     */
    void setSolved(bool solved);

private:
    std::string id;           /**< The identifier for the issue type. */
    std::string description;  /**< The textual description of the issue. */
    bool solved;              /**< Indicates whether the issue is resolved. */
};

#endif
