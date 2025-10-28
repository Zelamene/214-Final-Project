#ifndef EFTPAYMENT_H
#define EFTPAYMENT_H

#include "PaymentStrategy.h"

class EFTPayment : public PaymentStrategy {
public:
    bool pay(double amount) override;
};

#endif // EFTPAYMENT_H
