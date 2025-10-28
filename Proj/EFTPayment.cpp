#include "EFTPayment.h"
#include <iostream>

bool EFTPayment::pay(double amount) {
    std::cout << "Paid R" << amount << " via EFT." << std::endl;
    return true;
}
