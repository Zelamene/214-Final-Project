#ifndef FERTILIZEBEDCOMMAND_H
#define FERTILIZEBEDCOMMAND_H
#include "Command.h"
#include "NurseryPlant.h"
#include "Customer.h"
#include "Order.h"
class FertilizeBedCommand : public Command {
private:
    Order* order;
    std :: string bedName;
public:
    FertilizeBedCommand(std :: string b) : bedName(b) {}
    void execute() override {
        std :: cout << "Fertilizing bed: " << bedName << "\n";
    }
};

#endif