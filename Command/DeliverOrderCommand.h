#ifndef DELIVERORDERCOMMAND_H
#define DELIVERORDERCOMMAND_H
#include "Command.h"
#include "NurseryPlant.h"
#include "Customer.h"
#include "Order.h"
class DeliverOrderCommand : public Command {
private:
    Order* order;
public:
    DeliverOrderCommand(Order* o) : order(o) {}
    void execute() override {
        std :: cout << "Delivering order #" << order->getId()
             << " to " << order->getCustomer()->getName() << "\n";
        order->setState("delivered");
    }
};

#endif