// Note tafazwa your code brakes when you enter invalid input such as characters when numbers are expected.

#include <iostream>
#include "LowMaintenancePlantFactory.h"
#include "HighMaintenancePlantFactory.h"
#include "Garden.h"
#include "CrateFactory.h"
#include "NurseryPlant.h"
#include "BulkOrder.h"
#include "OrderSlip.h"
#include "RefundSlip.h"
#include "NurseryPlant.h"
#include "ConcreteState.h"
#include "Staff.h"
#include "Inventory.h"

#include <string>

int main() {
    std::cout << "=== Welcome to the Plant Nursery Simulator ===\n\n";
    Garden myGarden;
    Inventory* storage = new Inventory();
    Staff* staff = new Staff(storage);

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
            default: std::cout << "Invalid choice!"  << std::endl; continue;
        }

        if (newPlant) {       
            
            cout<<"===== Plant Info=====\n"<<endl;

            newPlant->displayInfo();

            cout<<"===== END =====\n"<<endl;


            newContainer = crateFactory.createContainer();

           
            myGarden.addPlant(newPlant, newContainer);
            newPlant->attach(staff);
            newPlant->startGrowing();
            
        }
    }

    std::cout << "\nFinal Garden Contents:\n";
    myGarden.displayPlants();
    
    std::cout << "\nFinal Inventory State:\n";
    storage->displayInventory();

    cout<<"Processing a sample bulk order and generating an order slip...\n"<<endl;

    BulkOrder* bulkOrder = new BulkOrder(); // Example bulk order
    // Add some plants to the bulk order for demonstration

    while(true){
        cout<<"this is whats in the inventory now "<<endl;
        storage->displayInventory();
        cout<<"Enter the name of the plant you want to order (or 'done' to finish): ";
        string plantName;
        cin>>plantName;
        Order* plant=storage->removePlant(plantName);
        if(plant){
            cout<<"===== Plant Details=====\n"<<endl;
            plant->displayDetails();
            plant->calculateTax();
            plant->displayDetails();

            bulkOrder->addOrder(plant);
            cout<<"Added "<<plantName<<" to the bulk order."<<endl;
        }else{
            cout<<"Plant not found in inventory."<<endl;
        }  

        if(plantName=="done"){
            break;
        }

    }

    bulkOrder->displayDetails();
    bulkOrder->calculateTax();

    cout << "\n=== Testing Iterator Pattern ===" << endl;
    Iterator *it = bulkOrder->createIterator();
    while (it->hasNext())
    {
        Order *o = it->next();
        o->displayDetails();
    }

        try
    {
        it->next();
    }
    catch (const out_of_range &e)
    {
        cout << "After finishing exception: " << e.what() << endl;
    }
    delete it;


    BulkOrder *emptyBulk = new BulkOrder();
    Iterator *emptyIt = emptyBulk->createIterator();
    cout << "\nIterating over empty bulk order:" << endl;
    if (!emptyIt->hasNext())
        cout << "No orders to iterate." << endl;
    delete emptyIt;
    delete emptyBulk;

    std::cout << "\nExiting Plant Nursery Simulator. Goodbye!\n";


    return 0;
}
