#include "CashierHandler.h"
#include "DisputeHandler.h"
#include "Issue.h"
using namespace std;
#include <iostream>

void CashierHandler::setPaymentStrategy(PaymentStrategy *strategy)
{
    delete payStrategy;
    payStrategy = strategy;
}
void CashierHandler::setSlipGenerator(SlipTemplate *slip)
{
    delete slipGenerator;
    slipGenerator = slip;
}
void CashierHandler::processIssue(Issue *issue)
{
    cout << "CashierHandler processing: "
              << issue->getDescription() << endl;

    string issueType = issue->getID();
    Order *order = issue->getOrder();

    if (issueType == "Payment")
    {
        if (order && payStrategy)
        {
            double amount = order->getTotal();
            cout << "Processing payment of $" << amount << "..." << endl;

            if (payStrategy->processPayment(amount))
            {
                cout << "Payment successful via "
                          << payStrategy->getMethodName() << endl;
            }
            else
            {
                cout << "Payment failed!" << endl;
            }
        }
        else
        {
            cout << " Missing order or payment method!" << endl;
        }
    }
    else if (issueType == "Refund")
    {
        if (order)
        {
            cout << "Processing refund for Order #" << order->getID() << endl;
            cout << "Refund amount: $" << order->getTotal() << endl;

            if (slipGenerator)
            {
                slipGenerator->setOrder(order);
                slipGenerator->printSlip();
            }
        }
        else
        {
            cout << " No order associated with refund!" << endl;
        }
    }
    else
    {
        cout << "Handling general cashier issue..." << endl;
    }

    cout << "Cashier issue resolved.\n"
              << endl;
}

bool CashierHandler::canHandle(Issue *issue) 
{
    string id = issue->getID();
    return (id == "Payment" || id == "Refund" || id == "Cashier");
}

CashierHandler ::CashierHandler() : payStrategy(NULL), slipGenerator(NULL)
{
}

CashierHandler ::~CashierHandler()
{
   
}