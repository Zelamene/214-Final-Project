#ifndef CARDPAYMENT_H
#define CARDPAYMENT_H

#include "PaymentStrategy.h"

class CardPayment : public PaymentStrategy {
public:
    bool pay(double amount) override;
};

#endif // CARDPAYMENT_H
