#ifndef CASHPAYMENT_H
#define CASHPAYMENT_H

#include "PaymentStrategy.h"

class CashPayment : public PaymentStrategy {
public:
    bool pay(double amount) override;
};

#endif // CASHPAYMENT_H
