
#include "CashPayment.h"
using namespace std;
CashPayment::CashPayment(double tendered) : tenderedAmount(tendered) {}

bool CashPayment::processPayment(double amount)
{
    bool success = (tenderedAmount >= amount);
    if (success)
    {
        double change = tenderedAmount - amount;
        cout << "Cash payment processed. Change: R" << change << endl;
    }
    else
    {
        cout << "Insufficient cash. Tendered: R" << tenderedAmount
                  << ", Required: R" << amount << endl;
    }
    return success;
}

string CashPayment::getMethodName() const
{
    return "Cash";
}

string CashPayment::getTransactionDetails() const
{
    return "Cash - Tendered: $" + to_string(tenderedAmount);
}