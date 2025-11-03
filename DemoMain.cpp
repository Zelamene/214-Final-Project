#include "HighMaintenancePlantFactory.h"
#include "LowMaintenancePlantFactory.h"
#include "CrateFactory.h"
#include "Garden.h"
#include "ConcreteNurseryMediator.h"
#include "Customer.h"
#include "PlantExpert.h"
#include "Cashier.h"
#include "Manager.h"
#include "Nurse.h"
#include "Inventory.h"
#include "BulkOrder.h"
#include "OrderIterator.h"
#include "GiftWrap.h"
#include "BowDecorator.h"
#include "PrepareCommand.h"
#include "PackageOrderCommand.h"
#include "DeliverOrderCommand.h"
#include "CashPayment.h"
#include "CreditCardPayment.h"
#include "MobilePayment.h"
#include "OrderSlip.h"
#include "RefundSlip.h"
#include "CashierHandler.h"
#include "ManagerHandler.h"
#include "Issue.h"
#include "Invoker.h"
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Global system components
unique_ptr<Garden> nurseryGarden;
unique_ptr<Inventory> inventory;
unique_ptr<ConcreteNurseryMediator> mediator;
unique_ptr<PlantExpert> expert;
unique_ptr<Cashier> cashier;
unique_ptr<Manager> manager;
unique_ptr<Nurse> nurse;
unique_ptr<Customer> customer;
unique_ptr<BulkOrder> currentOrder;
vector<unique_ptr<Order>> completedOrders;

// Factories
unique_ptr<PlantFactory> highMaintenanceFactory;
unique_ptr<PlantFactory> lowMaintenanceFactory;
unique_ptr<ContainerFactory> crateFactory;

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pauseScreen()
{
    cout << "\nPress Enter to continue...";
    cin.get();
}

void displayHeader(const string &title)
{
    cout << "\n========================================\n";
    cout << "  " << title << "\n";
    cout << "========================================\n";
}

void initializeSystem()
{
    displayHeader("INITIALIZING NURSERY SYSTEM");

    //  garden
    nurseryGarden = make_unique<Garden>();

    //  factories
    highMaintenanceFactory = make_unique<HighMaintenancePlantFactory>();
    lowMaintenanceFactory = make_unique<LowMaintenancePlantFactory>();
    crateFactory = make_unique<CrateFactory>();

    //  inventory and mediator
    inventory = make_unique<Inventory>();
    mediator = make_unique<ConcreteNurseryMediator>();
    mediator->setInventory(inventory.get());

    //  staff
    expert = make_unique<PlantExpert>(inventory.get(), "Dr. Ngwenya");
    cashier = make_unique<Cashier>(inventory.get(), "Thandah", nurseryGarden.get());
    manager = make_unique<Manager>(inventory.get(), "Ms. H", nurseryGarden.get());
    nurse = make_unique<Nurse>(inventory.get(), "Kyle");

    //  staff
    mediator->addStaff(expert.get());
    mediator->addStaff(cashier.get());
    mediator->addStaff(manager.get());
    mediator->addStaff(nurse.get());

    cout << "\n✓ System initialized successfully!\n";
    cout << "✓ Staff members registered\n";
    cout << "✓ Garden and inventory ready\n";
    pauseScreen();
}

void staffMenu()
{
    while (true)
    {
        displayHeader("STAFF OPERATIONS");
        cout << "1. Plant new flowers\n";
        cout << "2. Plant new trees\n";
        cout << "3. Grow all plants to maturity\n";
        cout << "4. View garden status\n";
        cout << "5. View inventory\n";
        cout << "0. Back to main menu\n";
        cout << "\nChoice: ";

        int choice;
        cin >> choice;
        clearInput();

        switch (choice)
        {
        case 1:
        {
            displayHeader("PLANTING FLOWERS");
            cout << "1. Low Maintenance (Rose)\n";
            cout << "2. High Maintenance (Cherry Blossom)\n";
            cout << "Choice: ";

            int type;
            cin >> type;
            clearInput();

            cout << "Enter price: R";
            double price;
            cin >> price;
            clearInput();

            cout << "Enter color: ";
            string color;
            getline(cin, color);

            cout << "Enter container material: ";
            string material;
            getline(cin, material);

            NurseryPlant *plant = nullptr;
            if (type == 1)
            {
                plant = lowMaintenanceFactory->createFloweringPlant(price, color);
            }
            else
            {
                plant = highMaintenanceFactory->createFloweringPlant(price, color);
            }

            Container *container = crateFactory->createContainer(material);
            nurseryGarden->addPlant(plant, container);

            cout << "\n✓ Plant added to garden!\n";
            pauseScreen();
            break;
        }
        case 2:
        {
            displayHeader("PLANTING TREES");
            cout << "1. Low Maintenance (Aloe)\n";
            cout << "2. High Maintenance (Baobab)\n";
            cout << "Choice: ";

            int type;
            cin >> type;
            clearInput();

            cout << "Enter height (meters): ";
            double height;
            cin >> height;
            clearInput();

            cout << "Enter price: R";
            double price;
            cin >> price;
            clearInput();

            cout << "Enter container material: ";
            string material;
            getline(cin, material);

            NurseryPlant *plant = nullptr;
            if (type == 1)
            {
                plant = lowMaintenanceFactory->createTree(height, price);
            }
            else
            {
                plant = highMaintenanceFactory->createTree(height, price);
            }

            Container *container = crateFactory->createContainer(material);
            nurseryGarden->addPlant(plant, container);

            cout << "\n✓ Tree added to garden!\n";
            pauseScreen();
            break;
        }
        case 3:
        {
            displayHeader("GROWING PLANTS");
            cout << "Growing all plants to maturity...\n\n";

            auto plants = nurseryGarden->getAllPlants();
            for (auto *plant : plants)
            {
                // Attach observers
                plant->attach(nurse.get());
                plant->attach(expert.get());
                plant->attach(manager.get());

                // Set water and grow
                plant->setWaterlevel(100);
                plant->startGrowing();
            }

            cout << "\n✓ All plants grown to maturity!\n";
            cout << "✓ Inventory updated\n";
            pauseScreen();
            break;
        }
        case 4:
        {
            displayHeader("GARDEN STATUS");
            nurseryGarden->displayPlants();
            cout << "\nTotal plants: " << nurseryGarden->getPlantCount() << "\n";
            pauseScreen();
            break;
        }
        case 5:
        {
            displayHeader("INVENTORY");
            inventory->displayInventory();
            pauseScreen();
            break;
        }
        case 0:
            return;
        default:
            cout << "Invalid choice!\n";
            pauseScreen();
        }
    }
}

void customerMenu()
{
    if (!customer)
    {
        cout << "Enter customer name: ";
        string name;
        getline(cin, name);
        customer = make_unique<Customer>(name, mediator.get());
        mediator->addCustomer(customer.get());
        cout << "\n✓ Welcome, " << name << "!\n";
        pauseScreen();
    }

    while (true)
    {
        displayHeader("CUSTOMER MENU");
        cout << "Customer: " << customer->getName() << "\n";
        cout << "----------------------------------------\n";
        cout << "1. Browse plants\n";
        cout << "2. Request plant advice\n";
        cout << "3. Purchase plants\n";
        cout << "4. View current order\n";
        cout << "5. Checkout\n";
        cout << "6. File complaint\n";
        cout << "0. Back to main menu\n";
        cout << "\nChoice: ";

        int choice;
        cin >> choice;
        clearInput();

        switch (choice)
        {
        case 1:
        {
            displayHeader("BROWSING PLANTS");
            customer->browsePlants();
            pauseScreen();
            break;
        }
        case 2:
        {
            displayHeader("REQUEST ADVICE");
            cout << "1. Low maintenance plants\n";
            cout << "2. High maintenance plants\n";
            cout << "Choice: ";

            int adviceChoice;
            cin >> adviceChoice;
            clearInput();

            if (adviceChoice == 1)
            {
                customer->requestAdvice("low-maintenance");
            }
            else
            {
                customer->requestAdvice("high-maintenance");
            }
            pauseScreen();
            break;
        }
        case 3:
        {
            displayHeader("PURCHASE PLANTS");
            inventory->displayInventory();

            cout << "\nEnter plant name to purchase (or 'done'): ";
            string plantName;
            getline(cin, plantName);

            while (plantName != "done" && plantName != "DONE")
            {
                if (inventory->hasStock(plantName, 1))
                {
                    customer->purchasePlant(plantName);

                    NurseryPlant *plant = inventory->previewPlantForSale(plantName);
                    if (plant)
                    {
                        // Ask about decoration
                        cout << "\nAdd gift wrap and bow? (y/n): ";
                        char decorate;
                        cin >> decorate;
                        clearInput();

                        if (decorate == 'y' || decorate == 'Y')
                        {
                            plant = new BowDecorator(new GiftWrap(plant));
                            cout << "✓ Plant decorated! New price: R" << plant->getTotal() << "\n";
                        }

                        // Add to order
                        if (!currentOrder)
                        {
                            currentOrder = make_unique<BulkOrder>();
                            currentOrder->setCustomer(customer.get());
                        }
                        currentOrder->addOrder(plant);
                        cout << "✓ Added to order!\n";
                    }
                }
                else
                {
                    cout << "✗ Plant not in stock!\n";
                }

                cout << "\nEnter another plant name (or 'done'): ";
                getline(cin, plantName);
            }
            pauseScreen();
            break;
        }
        case 4:
        {
            displayHeader("CURRENT ORDER");
            if (currentOrder && currentOrder->getTotal() > 0)
            {
                unique_ptr<Iterator> it(currentOrder->createIterator());
                int count = 1;
                while (it->hasNext())
                {
                    Order *item = it->next();
                    cout << count++ << ". " << item->getID()
                         << " - R" << item->getTotal() << "\n";
                }
                cout << "\nTotal: R" << currentOrder->getTotal() << "\n";
            }
            else
            {
                cout << "No items in order.\n";
            }
            pauseScreen();
            break;
        }
        case 5:
        {
            displayHeader("CHECKOUT");
            if (!currentOrder || currentOrder->getTotal() == 0)
            {
                cout << "No items to checkout!\n";
                pauseScreen();
                break;
            }

            // Display order
            OrderSlip orderSlip(currentOrder.get());
            orderSlip.printSlip();

            // Payment method
            cout << "\nSelect payment method:\n";
            cout << "1. Cash\n";
            cout << "2. Credit Card\n";
            cout << "3. Mobile Payment\n";
            cout << "Choice: ";

            int payChoice;
            cin >> payChoice;
            clearInput();

            unique_ptr<PaymentStrategy> payment;

            switch (payChoice)
            {
            case 1:
            {
                cout << "Amount tendered: R";
                double tendered;
                cin >> tendered;
                clearInput();
                payment = make_unique<CashPayment>(tendered);
                break;
            }
            case 2:
            {
                cout << "Card number: ";
                string cardNum;
                getline(cin, cardNum);
                cout << "Expiry (MM/YY): ";
                string expiry;
                getline(cin, expiry);
                payment = make_unique<CreditCardPayment>(cardNum, expiry);
                break;
            }
            case 3:
            {
                cout << "Phone number: ";
                string phone;
                getline(cin, phone);
                cout << "Provider (e.g., MTN, Vodacom): ";
                string provider;
                getline(cin, provider);
                payment = make_unique<MobilePayment>(phone, provider);
                break;
            }
            default:
                cout << "Invalid choice!\n";
                pauseScreen();
                continue;
            }

            cashier->setPaymentStrategy(payment.get());

            if (payment->processPayment(currentOrder->getTotal()))
            {
                cout << "\n✓ Payment successful!\n";

                // Process order
                Invoker orderManager;
                PackageOrderCommand packageCmd(currentOrder.get());
                DeliverOrderCommand deliverCmd(currentOrder.get());

                orderManager.addCommand(&packageCmd);
                orderManager.addCommand(&deliverCmd);
                orderManager.processCommands();

                cout << "\n✓ Order completed!\n";


                completedOrders.push_back(unique_ptr<Order>(currentOrder->clone()));


                currentOrder.reset();

            }
            else
            {
                cout << "\n✗ Payment failed!\n";
            }
            pauseScreen();
            break;
        }
        case 6:
        {
            displayHeader("FILE COMPLAINT");
            cout << "Enter complaint: ";
            string complaint;
            getline(cin, complaint);

            customer->send("Complaint: " + complaint);
 if (complaint.find("refund") != string::npos || complaint.find("Refund") != string::npos)
{
    if (!completedOrders.empty())
    {
        cout << "\nRefund request detected.\n";

        // Use last completed order for refund
        Order* lastOrder = completedOrders.back().get();

        // Clone it for processing (Prototype pattern)
        unique_ptr<Order> refundOrder(lastOrder->clone());
        cout << "\nRefund order cloned from original.\n";
        cout << "Original order ID: " << lastOrder->getID() << "\n";
        cout << "Refund order ID: " << refundOrder->getID() << "\n";
        cout << "Refund total: R" << refundOrder->getTotal() << "\n";

        // Generate refund slip (Template Method pattern)
        cout << "\nGenerating refund slip...\n";
        RefundSlip refundSlip(refundOrder.get());
        refundSlip.printSlip();

        // Handle refund through Chain of Responsibility
        cout << "\nProcessing refund through dispute handler chain...\n";
        Issue refundIssue("Refund", "Processing refund for order", refundOrder.get());

        CashierHandler cashierHandler;
        cashierHandler.setSlipGenerator(&refundSlip);
        ManagerHandler managerHandler;
        cashierHandler.setNext(&managerHandler);
        cashierHandler.handle(&refundIssue);

        cout << "\n✓ Refund processed successfully!\n";
    }
    else
    {
        cout << "\n✗ No completed orders available for refund.\n";
    }
}
            pauseScreen();
            break;
        }
        case 0:
            return;
        default:
            cout << "Invalid choice!\n";
            pauseScreen();
        }
    }
}

void quickDemo()
{
    displayHeader("QUICK DEMONSTRATION");
    cout << "Running automated demonstration...\n\n";

    // Plant
    cout << "1. Planting plants...\n";
    for (int i = 0; i < 2; i++)
    {
        NurseryPlant *rose = lowMaintenanceFactory->createFloweringPlant(45.0, "Red");
        NurseryPlant *cherry = highMaintenanceFactory->createFloweringPlant(65.0, "Pink");
        NurseryPlant *aloe = lowMaintenanceFactory->createTree(0.5, 35.0);
        NurseryPlant *baobab = highMaintenanceFactory->createTree(1.2, 120.0);

        Container *c1 = crateFactory->createContainer("Wood");
        Container *c2 = crateFactory->createContainer("Cedar");
        Container *c3 = crateFactory->createContainer("Plastic");
        Container *c4 = crateFactory->createContainer("Large Wood");

        nurseryGarden->addPlant(rose, c1);
        nurseryGarden->addPlant(cherry, c2);
        nurseryGarden->addPlant(aloe, c3);
        nurseryGarden->addPlant(baobab, c4);
    }

    cout << "✓ 8 plants added\n\n";

    // Grow them
    cout << "2. Growing plants...\n";
    auto plants = nurseryGarden->getAllPlants();
    for (auto *plant : plants)
    {
        plant->attach(nurse.get());
        plant->attach(expert.get());
        plant->attach(manager.get());
        plant->setWaterlevel(100);
        plant->startGrowing();
    }
    cout << "✓ All plants matured\n\n";

    // Show inventory
    cout << "3. Current Inventory:\n";
    inventory->displayInventory();

    cout << "\n✓ Demo complete!\n";
    pauseScreen();
}

int main()
{
    cout << "\n";
    cout << "\n";
    cout << "   NURSERY MANAGEMENT SYSTEM       \n";
    cout << "   Design Patterns Demonstration   \n";
    cout << "\n";

    initializeSystem();

    bool running = true;
    while (running)
    {
        displayHeader("MAIN MENU");
        cout << "1. Staff Operations\n";
        cout << "2. Customer Operations\n";
        cout << "3. Run Quick Demo(Create and Grow Plants To Maturity)\n";
        cout << "4. View System Status(Inventory Status)\n";
        cout << "0. Exit\n";
        cout << "\nChoice: ";

        int choice;
        cin >> choice;
        clearInput();

        switch (choice)
        {
        case 1:
            staffMenu();
            break;
        case 2:
            customerMenu();
            break;
        case 3:
            quickDemo();
            break;
        case 4:
        {
            displayHeader("SYSTEM STATUS");
            cout << "Garden: " << nurseryGarden->getPlantCount() << " plants\n";
            cout << "\nInventory:\n";
            inventory->displayInventory();
            if (customer)
            {
                cout << "\nCurrent Customer: " << customer->getName() << "\n";
            }
            pauseScreen();
            break;
        }
        case 0:
            cout << "\nThank you for shopping with us!\n";
            running = false;
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            pauseScreen();
        }
    }

    return 0;
}