#ifndef DISPUTEHANDLER_H
#define DISPUTEHANDLER_H

#include "Issue.h"

/**
 * @class DisputeHandler
 * @brief Abstract base class that defines the interface for handling issues in a chain of responsibility.
 *
 * Each concrete handler (e.g., CashierHandler, ManagerHandler) extends this class and decides
 * whether to handle an Issue or pass it to the next handler in the chain.
 */
class DisputeHandler
{
public:
    /**
     * @brief Constructs a DisputeHandler with no next handler.
     */
    DisputeHandler();

    /**
     * @brief Virtual destructor that also deletes the next handler to avoid memory leaks.
     */
    virtual ~DisputeHandler();

    /**
     * @brief Sets the next handler in the chain.
     * @param next Pointer to the next DisputeHandler.
     */
    void setNext(DisputeHandler* next);

    /**
     * @brief Handles an issue or passes it to the next handler if unhandled.
     * @param issue Pointer to the Issue object to be processed.
     */
    virtual void handle(Issue* issue);

protected:
    /** Pointer to the next handler in the chain. */
    DisputeHandler* next;
};

#endif
