#ifndef CASHIERHANDLER_H
#define CASHIERHANDLER_H

#include "Issue.h"
#include "DisputeHandler.h"
#include <string>

/**
 * @class CashierHandler
 * @brief Concrete handler that processes issues related to the cashier.
 *
 * If the issue ID matches "Cashier", this handler solves it.
 * Otherwise, it passes the issue to the next handler in the chain.
 */
class CashierHandler : public DisputeHandler
{
public:
    /**
     * @brief Constructs a CashierHandler with no next handler.
     */
    CashierHandler();

    /**
     * @brief Destroys the CashierHandler instance.
     */
    virtual ~CashierHandler();

    /**
     * @brief Handles cashier-related issues or passes them to the next handler.
     * @param issue Pointer to the Issue object.
     */
    void handle(Issue* issue);
};

#endif
