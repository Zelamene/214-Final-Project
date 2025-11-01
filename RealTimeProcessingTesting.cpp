#include <iostream>
#include "HighMaintenancePlantFactory.h"
#include "LowMaintenancePlantFactory.h"
#include "CrateFactory.h"
#include "Garden.h"
#include "Staff.h"
#include "Inventory.h"
#include "BulkOrder.h"
#include "OrderSlip.h"
#include "RefundSlip.h"
#include "CashierHandler.h"
#include "ManagerHandler.h"
#include "CashPayment.h"
#include "CreditCardPayment.h"
#include "WaterPlantCommand.h"
#include "PrepareCommand.h"
#include "PackageOrderCommand.h"
#include "DeliverOrderCommand.h"
#include "Invoker.h"
#include "Nurse.h"
#include "Manager.h"
#include "PlantExpert.h"
#include "RoseCare.h"
#include "AloeCare.h"
#include "BaobabCare.h"
#include "CherryCare.h"
#include "ConcreteNurseryMediator.h"
#include "Customer.h"
#include "GiftWrap.h"
#include "BowDecorator.h"

int main()
{
    std::cout << "===  PLANT NURSERY - REAL TIME SIMULATION ===\n\n\n\n";
    srand(time(0));

    // Create mediator first
    ConcreteNurseryMediator *mediator = new ConcreteNurseryMediator();
    Inventory *inventory = new Inventory();
    mediator->setInventory(inventory);

    //
    //  1: MORNING SETUP - MANAGER PREPARES THE NURSERY
    //
    std::cout << " 8:00 AM - MORNING SETUP\n\n";
    std::cout << "===========================\n\n";

    // Manager arrives and sets up inventory through mediator
    std::cout << "Manager John arrives and opens the nursery...\n\n";
    Manager *manager = new Manager(inventory, "Manager Kyle");
    mediator->addStaff(manager);

    // Manager hires staff for the day through mediator
    std::cout << "Manager is hiring staff for today...\n\n";
    Nurse *nurse = new Nurse(inventory, "Nurse Sarah");
    PlantExpert *expert = new PlantExpert(inventory, "Expert Dr. Ngwenya");
    Staff *cashier = new Staff(inventory, "Cashier Mike");

    mediator->addStaff(nurse);
    mediator->addStaff(expert);
    mediator->addStaff(cashier);

    // Manager communicates with staff through mediator
    manager->send("Adding staff members to roster");
    manager->addStaffMember(nurse->getName());
    manager->addStaffMember(expert->getName());
    manager->addStaffMember(cashier->getName());

    std::cout << "Today's staff: ";
    for (const auto &staff : manager->getStaffMembers())
    {
        std::cout << staff << " ";
    }
    std::cout << "\n\n\n\n";

    //
    //  2: PLANT PREPARATION - NURSE CHECKS THE GARDEN
    //
    std::cout << " 9:00 AM - PLANT CARE ROUNDS\n\n";
    std::cout << "==============================\n\n";

    // Create plants in the garden (not ready for sale yet)
    LowMaintenancePlantFactory lowFactory;
    HighMaintenancePlantFactory highFactory;

    auto *rose = highFactory.createFloweringPlant(45.0);
    auto *aloe = lowFactory.createTree(0.8, 25.0);
    auto *baobab = highFactory.createTree(3.0, 150.0);
    auto *cherryBlossom = highFactory.createFloweringPlant(80.0);

    Garden garden;
    CrateFactory crateFact;
    garden.addPlant(rose, crateFact.createContainer("Wood"));
    garden.addPlant(aloe, crateFact.createContainer("Ceramic"));
    garden.addPlant(baobab, crateFact.createContainer("Plastic"));
    garden.addPlant(cherryBlossom, crateFact.createContainer("Wood"));

    std::cout << "Nurse Sarah begins her morning plant check...\n\n";
    nurse->send("Starting morning plant care rounds");

    std::cout << "Current garden status (staff only):\n\n";
    garden.displayPlants();

    // Attach staff as observers to monitor plant growth
    rose->attach(nurse);
    aloe->attach(nurse);
    baobab->attach(manager);
    cherryBlossom->attach(expert);

    // Nurse performs care routines to help plants grow through mediator
    std::cout << "\n\nNurse tending to plants to help them mature...\n\n";
    nurse->send("Performing care routines for Rose and Aloe");
    nurse->tendToPlants(rose);
    nurse->tendToPlants(aloe);

    std::cout << "\n\n";

    //  3: PLANT GROWTH - STAFF OBSERVES MATURATION

    std::cout << "10:00 AM - PLANT GROWTH & MATURATION\n\n";
    std::cout << "=======================================\n\n";

    std::cout << "Plants are growing under staff care...\n\n";
    manager->send("Monitoring plant growth progress");

    // Simulate plants growing to maturity
    std::cout << "Rose plant growth:\n\n";
    rose->startGrowing(); // Observers get notified when mature

    std::cout << "\n\nAloe plant growth:\n\n";
    aloe->startGrowing(); // Observers get notified when mature

    std::cout << "\n\nCherry Blossom growth:\n\n";
    cherryBlossom->startGrowing(); // Expert gets notified

    // Staff have automatically added mature plants to inventory via Observer pattern
    std::cout << "\n\nStaff have updated inventory with mature plants:\n\n";
    inventory->displayInventory();

    std::cout << "\n\n";

    //  4: CUSTOMER ARRIVES - BROWSES AVAILABLE INVENTORY

    std::cout << "11:00 AM - CUSTOMER ARRIVES\n\n";
    std::cout << "==============================\n\n";

    std::cout << "Customer Alice enters the nursery...\n\n";
    Customer *alice = new Customer("Alice", mediator);
    mediator->addCustomer(alice);

    // Customer sees only what's available in inventory (mature plants ready for sale)
    std::cout << "Alice browses available plants for sale:\n\n";
    alice->browsePlants(); // This goes through mediator
    inventory->displayInventory();

    // Customer asks expert for advice from staff through mediator
    std::cout << "Alice: 'I need a low-maintenance plant for my office.'\n\n";
    alice->requestAdvice("low-maintenance"); // → Mediator → Expert

    // Customer decides to purchase Aloe from inventory through mediator
    std::cout << "Alice: 'I'll take the Aloe plant!'\n\n";
    alice->purchasePlant("Aloe"); // → Mediator → Inventory check → Staff notification

    // DECORATOR PATTERN - Customer chooses decoration option
    std::cout << "Cashier: 'Would you like gift wrapping or bow decoration?'\n\n";

    NurseryPlant *decoratedAloe = aloe; // Start with base plant

    // Customer chooses gift wrapping through mediator
    std::cout << "Alice: 'Yes, I'd like gift wrapping please.'\n\n";
    decoratedAloe = new GiftWrap(aloe);                      // Wrap with gift decoration
    alice->send("Alice wants gift wrapping for Aloe plant"); // Notify staff through mediator

    std::cout << "Gift wrapping added: " << dynamic_cast<GiftWrap *>(decoratedAloe)->getDescription() << "\n\n";

    // Create order for the customer with decorated plant
    decoratedAloe->setCustomer(alice);
    std::cout << "Order created for Alice - " << dynamic_cast<GiftWrap *>(decoratedAloe)->getDescription()
              << ": R" << decoratedAloe->getTotal() << " (Base: R" << aloe->getTotal()
              << " + Gift Wrap: R15.00)\n\n\n\n";

    //  5: PAYMENT PROCESSING - CASHIER HANDLES TRANSACTION

    std::cout << "12:00 PM - PAYMENT PROCESSING\n\n";
    std::cout << "================================\n\n";

    std::cout << "Alice proceeds to checkout...\n\n";
    alice->send("Alice proceeding to checkout with Aloe plant");

    // Set up payment chain
    CashierHandler cashierHandler;
    ManagerHandler managerHandler;
    cashierHandler.setNext(&managerHandler);
    cashierHandler.setPaymentStrategy(new CashPayment(50.0)); // Alice pays cash
    cashierHandler.setSlipGenerator(new OrderSlip(decoratedAloe));

    // Process payment
    Issue paymentIssue("Payment", "Alice paying for decorated Aloe plant", decoratedAloe);
    cashierHandler.handle(&paymentIssue);

    // Remove sold plant from inventory through mediator
    alice->send("Completed purchase of Aloe plant - remove from inventory");
    std::cout << "Aloe removed from inventory after sale.\n\n";

    std::cout << "Updated inventory:\n\n";
    inventory->displayInventory();

    std::cout << "\n\n";

    //  6: ORDER FULFILLMENT - PREPARE AND PACKAGE

    std::cout << "1:00 PM - ORDER PREPARATION\n\n";
    std::cout << "===============================\n\n";

    std::cout << "Preparing Alice's decorated order for pickup...\n\n";
    alice->send("Preparing order for pickup with gift wrapping");

    Invoker orderInvoker;
    PrepareCommand prepareCmd(decoratedAloe);
    PackageOrderCommand packageCmd(decoratedAloe);
    DeliverOrderCommand deliverCmd(decoratedAloe);

    orderInvoker.addCommand(&prepareCmd);
    orderInvoker.addCommand(&packageCmd);
    orderInvoker.addCommand(&deliverCmd);

    orderInvoker.processCommands();

    std::cout << "Alice's decorated order is ready for pickup!\n\n";
    std::cout << "Final product: " << dynamic_cast<GiftWrap *>(decoratedAloe)->getDescription() << "\n\n\n\n";

    //  7: AFTERNOON CUSTOMER - MORE PLANTS MATURE

    std::cout << "3:00 PM - AFTERNOON BUSINESS\n\n";
    std::cout << "===============================\n\n";

    std::cout << "Customer Bob arrives...\n\n";
    Customer *bob = new Customer("Bob", mediator);
    mediator->addCustomer(bob);

    // More plants have matured during the day
    std::cout << "Additional plants have matured and been added to inventory:\n\n";
    manager->send("Baobab tree reached maturity - added to inventory");
    std::cout << "Baobab tree reached maturity and was added to inventory.\n\n";

    bob->browsePlants(); // View inventory through mediator
    inventory->displayInventory();

    // Bob wants to buy multiple plants (composite) through mediator
    std::cout << "Bob: 'I'll take the Rose and Cherry Blossom!'\n\n";
    bob->purchasePlant("Rose");
    bob->purchasePlant("Cherry Blossom");

    // Create bulk order
    bool orderProcessed = false;
    BulkOrder bobOrder;
    if (inventory->hasStock("Rose", 1) && inventory->hasStock("Cherry Blossom", 1))
    {
        orderProcessed = true;
        BulkOrder bobOrder;
        bobOrder.addOrder(rose);
        bobOrder.addOrder(rose->clone());
        bobOrder.addOrder(cherryBlossom);

        rose->setCustomer(bob);
        cherryBlossom->setCustomer(bob);

        std::cout << "Bob's order total: R" << bobOrder.getTotal() << "\n\n";

        // Process bulk order payment
        cashierHandler.setPaymentStrategy(new CreditCardPayment("1234567812345678", "12/25"));
        bob->send("Processing bulk order payment with credit card");

        Issue bulkPaymentIssue("Payment", "Bob paying for multiple plants", &bobOrder);
        cashierHandler.handle(&bulkPaymentIssue);

        // Update inventory through mediator
        bob->send("Completed bulk purchase - remove Rose and Cherry Blossom from inventory");
        std::cout << "\n\nUpdated inventory after Bob's purchase:\n\n";
        inventory->displayInventory();
    }
    else
    {
        cout << "❌ Bob's order cancelled - insufficient stock.\n";
        bob->receive("We're sorry, some items in your order are out of stock.");
    }

    std::cout << "\n\n";

    //  8: STAFF COORDINATION - MANAGER OVERSEEING

    std::cout << " 4:00 PM - STAFF COORDINATION\n\n";
    std::cout << "===============================\n\n";

    std::cout << "Manager John conducts afternoon staff check...\n\n";
    manager->send("Conducting afternoon staff performance review");
    manager->reviewStaffPerformance();

    // Check remaining garden plants
    std::cout << "\n\nRemaining plants in garden (not yet mature):\n\n";
    garden.displayPlants();

    std::cout << "\n\n";

    //
    //  9: END OF DAY - REPORTING AND PLANNING
    //
    std::cout << "5:00 PM - END OF DAY\n\n";
    std::cout << "=======================\n\n";

    std::cout << "Closing time - generating end of day reports...\n\n";
    manager->send("Generating end of day reports");

    // Final inventory status
    std::cout << "\n\nFinal Inventory Status:\n\n";
    inventory->displayInventory();

    // Garden status for tomorrow
    std::cout << "\n\nGarden Status (plants still growing):\n\n";
    garden.displayPlants();

    // Sales summary
    std::cout << "\n\nToday's Sales Summary:\n\n";
    std::cout << "- Sold: " << dynamic_cast<GiftWrap *>(decoratedAloe)->getDescription() << " to Alice (R" << decoratedAloe->getTotal() << ")\n\n";
    if (orderProcessed)
    {
        std::cout << "- Sold: Rose & Cherry Blossom to Bob (R" << bobOrder.getTotal() << ")\n\n";
    }

    // Staff sends closing messages through mediator
    nurse->send("End of day plant care completed");
    expert->send("End of day consultations finished");
    cashier->send("Register closed and balanced");

    std::cout << "\n\n===  END OF DAY - NURSERY CLOSED ===\n\n";

    delete decoratedAloe;
    delete alice;
    delete bob;
    delete manager;
    delete nurse;
    delete expert;
    delete cashier;
    delete mediator;
    delete inventory;

    return 0;
}