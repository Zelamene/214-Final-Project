#include "FertilizeBedCommand.h"

FertilizeBedCommand::FertilizeBedCommand(string b) {
    bedName = b;
}

void FertilizeBedCommand::execute() {
        cout << "Fertilizing bed: " << bedName << "\n";
    }

