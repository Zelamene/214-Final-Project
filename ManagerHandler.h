#ifndef MANAGERHANDLER_H
#define MANAGERHANDLER_H

#include "Issue.h"
#include "DisputeHandler.h"
#include <string>
using namespace std;

/**
 * @class ManagerHandler
 * @brief Concrete handler that processes issues meant for the manager.
 *
 * If the issue ID matches "Manager", this handler solves it.
 * Otherwise, it passes the issue along the chain.
 */
class ManagerHandler : public DisputeHandler
{
protected:
    /**
     * @copydoc DisputeHandler::processIssue(Issue* issue)
     */
    void processIssue(Issue *issue) override;

    /**
<<<<<<< HEAD
     * @copydoc DisputeHandler::canHandle(Issue* issue)
=======
     * DisputeHandler::canHandle(Issue* issue)
     */
    /**
     * @brief Constructs a ManagerHandler with no next handler.
     */
    ManagerHandler();

    /**
     * @brief Destroys the ManagerHandler instance.
     */
    virtual ~ManagerHandler();
};

#endif
