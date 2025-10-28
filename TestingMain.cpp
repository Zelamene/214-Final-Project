#include <iostream>
#include "LowMaintenancePlantFactory.h"
#include "HighMaintenancePlantFactory.h"
#include "Garden.h"
#include "CrateFactory.h"

int main() {
    std::cout << "=== Welcome to the Plant Nursery Simulator ===\n\n";

    Garden myGarden;

    LowMaintenancePlantFactory lowFactory;
    HighMaintenancePlantFactory highFactory;
    CrateFactory crateFactory; 

    int choice = 0;

    while (true) {
        std::cout << "\nMenu:\n"
                  << "1. Create Low Maintenance Flowering Plant (Rose)\n"
                  << "2. Create Low Maintenance Tree (Aloe)\n"
                  << "3. Create High Maintenance Flowering Plant (Cherry Blossom)\n"
                  << "4. Create High Maintenance Tree (Baobab)\n"
                  << "5. Display Garden\n"
                  << "6. Remove Plant from Garden\n"
                  << "7. Exit\n"
                  << "Choose an option: ";
        std::cin >> choice;

        if (choice == 7) break;

        NurseryPlant* newPlant = nullptr;
        Container* newContainer = nullptr;

        switch (choice) {
            case 1: newPlant = lowFactory.createFloweringPlant(); break;
            case 2: newPlant = lowFactory.createTree(); break;
            case 3: newPlant = highFactory.createFloweringPlant(); break;
            case 4: newPlant = highFactory.createTree(); break;
            case 5: myGarden.displayPlants(); continue;
            case 6: {
                myGarden.displayPlants();
                int index;
                std::cout << "Enter index of plant to remove: ";
                std::cin >> index;
                myGarden.removePlant(index);
                continue;
            }
            default: std::cout << "Invalid choice!" << std::endl; continue;
        }

        if (newPlant) {
            
            newContainer = crateFactory.createContainer();

           
            myGarden.addPlant(newPlant, newContainer);
        }
    }

    std::cout << "\nFinal Garden Contents:\n";
    myGarden.displayPlants();

    std::cout << "\nExiting Plant Nursery Simulator. Goodbye!\n";
    return 0;
}
