#include "CashPayment.h"
#include <iostream>

bool CashPayment::pay(double amount) {
    std::cout << "Paid $" << amount << " in cash." << std::endl;
    return true;
}
