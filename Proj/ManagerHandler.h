#ifndef MANAGERHANDLER_H
#define MANAGERHANDLER_H

#include "Issue.h"
#include "DisputeHandler.h"
#include <string>

/**
 * @class ManagerHandler
 * @brief Concrete handler that processes issues meant for the manager.
 *
 * If the issue ID matches "Manager", this handler solves it.
 * Otherwise, it passes the issue along the chain.
 */
class ManagerHandler : public DisputeHandler
{
public:
    /**
     * @brief Constructs a ManagerHandler with no next handler.
     */
    ManagerHandler();

    /**
     * @brief Destroys the ManagerHandler instance.
     */
    virtual ~ManagerHandler();

    /**
     * @brief Handles manager-related issues or passes them to the next handler.
     * @param issue Pointer to the Issue object.
     */
    void handle(Issue* issue);
};

#endif
