#include "CardPayment.h"
#include <iostream>

bool CardPayment::pay(double amount) {
    std::cout << "Paid R" << amount << " using card." << std::endl;
    return true;
}
