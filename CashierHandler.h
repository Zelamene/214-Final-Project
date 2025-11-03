#ifndef CASHIERHANDLER_H
#define CASHIERHANDLER_H

#include "Issue.h"
#include "SlipTemplate.h"
#include "PaymentStrategy.h"
#include "DisputeHandler.h"
#include <string>
using namespace std;

/**
 * @class CashierHandler
 * @brief Concrete handler that processes issues related to the cashier.
 *
 * If the issue ID matches "Cashier", this handler solves it.
 * Otherwise, it passes the issue to the next handler in the chain.
 */
class CashierHandler : public DisputeHandler
{
private:
    PaymentStrategy *payStrategy; /** Strategy for processing payments */
    SlipTemplate *slipGenerator;  /** Template for generating slips */

protected:
    /**
     * @copydoc DisputeHandler::processIssue(Issue* issue)
     * @brief Processes the issue if it can be handled.
     */
    void processIssue(Issue *issue) override;

    /**
     *
     * @copydoc DisputeHandler::canHandle(Issue* issue)
     * @brief Checks if this handler can process the issue.
     */
    bool canHandle(Issue *issue) override;

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
     * @brief Sets the payment strategy.
     * @param strategy PaymentStrategy instance to use.
     */
    void setPaymentStrategy(PaymentStrategy *strategy);

    /**
     * @brief Sets the slip generator template.
     * @param slip SlipTemplate instance to use.
     */
    void setSlipGenerator(SlipTemplate *slip);
};

#endif
