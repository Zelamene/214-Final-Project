#ifndef PREPARECOMMAND_H
#define PREPARECOMMAND_H
#include "Command.h"
#include "NurseryPlant.h"
#include "Customer.h"
#include "Order.h"
class PackageOrderCommand : public Command {
private:
    Order* order;
public:
    PackageOrderCommand(Order* o) : order(o) {}
    void execute() override {
        std :: cout << "Packaging order #" << order->getId() << " (" << order->getPlantName() << ")\n";
        order->setState("packaged");
    }
};

#endif