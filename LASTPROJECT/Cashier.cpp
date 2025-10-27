#include "Cashier.h"
#include <iostream>

Cashier::Cashier(const std::string& name, NurseryMediator* med) 
    : Staff(name, "Cashier", med) {}

void Cashier::processPayment(const std::string& customerName, double amount) {
    send("processing payment of R" + std::to_string(amount) + " for " + customerName);
}

void Cashier::confirmSale(const std::string& plantName) {
    send("confirmed sale of " + plantName);
}

void Cashier::requestStockCheck(const std::string& plantName) {
    send("needs stock check for " + plantName);
}

void Cashier::issueReceipt(const std::string& customerName) {
    send("issuing receipt for " + customerName);
}

void Cashier::performDuty() {
    send("is performing cashier duties - managing sales and payments");
}