
#include "CreditCardPayment.h"

CreditCardPayment::CreditCardPayment(const string& card, const string& expiry) 
    : cardNumber(card), expiryDate(expiry) {}

bool CreditCardPayment::processPayment(double amount) {
    // Simulate card processing with basic validation
    if (cardNumber.length() != 16) {
        cout << "Invalid card number length!" << endl;
        return false;
    }
    
    cout << "Processing credit card payment of $" << amount << endl;
    cout << "Card: ****-****-****-" << cardNumber.substr(12) << endl;
    cout << "Expiry: " << expiryDate << endl;
    
    // Simulate processing delay
    cout << "Authorization approved." << endl;
    return true;
}

string CreditCardPayment::getMethodName() const { 
    return "Credit Card"; 
}

string CreditCardPayment::getTransactionDetails() const {
    return "Credit Card - Ending: " + cardNumber.substr(12);
}