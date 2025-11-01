/**
 * @file MobilePayment.cpp
 * @brief Implementation of MobilePayment class.
 */

#include "MobilePayment.h"

MobilePayment::MobilePayment(const string &phone, const string &prov)
    : phoneNumber(phone), provider(prov) {}

bool MobilePayment::processPayment(double amount)
{
    cout << "Processing " << provider << " payment from " << phoneNumber << endl;
    cout << "Amount: $" << amount << endl;
    cout << "Sending authorization request to " << provider << "..." << endl;
    cout << "Payment confirmed via mobile." << endl;
    return true;
}

string MobilePayment::getMethodName() const
{
    return "Mobile Payment";
}

string MobilePayment::getTransactionDetails() const
{
    return provider + " - " + phoneNumber;
}