#include "PrepareCommand.h"
#include "NurseryPlant.h"

PrepareCommand :: PrepareCommand(Order* order){
    this->order = order;
}

void PrepareCommand::execute()  {
        std::cout << "Preparing order #" << order->getId()
                  << " (" << order->getPlantName() << ")\n";
        order->setState("prepared");
    }
