#include "PrepareCommand.h"
#include "NurseryPlant.h"

PrepareCommand :: PrepareCommand(Order* order){
    this->order = order;
}

void PrepareCommand::execute()  {
        cout << "Preparing order #" << order->getID()<<"\n";
        order->setOrderStatus("prepared");
    }
