#include "../catch_amalgamated.hpp"
#include "../HighMaintenancePlantFactory.h"
#include "../LowMaintenancePlantFactory.h"
#include "../CrateFactory.h"
#include "../Garden.h"
#include "../ConcreteNurseryMediator.h"
#include "../Customer.h"
#include "../PlantExpert.h"
#include "../Cashier.h"
#include "../Manager.h"
#include "../Nurse.h"
#include "../Inventory.h"
#include "../BulkOrder.h"
#include "../OrderIterator.h"
#include "../GiftWrap.h"
#include "../BowDecorator.h"
#include "../PrepareCommand.h"
#include "../PackageOrderCommand.h"
#include "../DeliverOrderCommand.h"
#include "../CashPayment.h"
#include "../CreditCardPayment.h"
#include "../MobilePayment.h"
#include "../OrderSlip.h"
#include "../RefundSlip.h"
#include "../CashierHandler.h"
#include "../ManagerHandler.h"
#include "../Issue.h"
#include "../RoseCare.h"
#include "../CherryCare.h"
#include "../AloeCare.h"
#include "../BaobabCare.h"
#include "../Invoker.h"
#include <memory>
#include <iostream>
using namespace std;
TEST_CASE("Complete Nursery Purchase Workflow with All Patterns", "[integration]")
{

    SECTION("Complete Customer Purchase Journey")
    {
        cout << "\n=== STARTING COMPLETE NURSERY WORKFLOW TEST ===\n\n";

        // STEP 1: ABSTRACT FACTORY - Create plants using factories
        cout << "\n--- STEP 1: Creating Plants (Abstract Factory Pattern) ---\n";

        unique_ptr<PlantFactory> highMaintenanceFactory = make_unique<HighMaintenancePlantFactory>();
        unique_ptr<PlantFactory> lowMaintenanceFactory = make_unique<LowMaintenancePlantFactory>();

        // STEP 1.5: FACTORY METHOD - Create containers for planting
        unique_ptr<ContainerFactory> crateFactory = make_unique<CrateFactory>();

        cout << "\n--- STEP 2: Planting in Garden (Factory Method Pattern) ---\n";

        Garden nurseryGarden;

        vector<NurseryPlant *> rosesToPlant;
        vector<NurseryPlant *> cherryBlossomsToPlant;
        vector<NurseryPlant *> aloesToPlant;
        vector<NurseryPlant *> baobabsToPlant;

        cout << "\nPlanting multiple specimens in containers...\n";

        for (int i = 0; i < 3; i++)
        {
            // Create plants
            NurseryPlant *rose = lowMaintenanceFactory->createFloweringPlant(45.0, "Red");
            NurseryPlant *cherry = highMaintenanceFactory->createFloweringPlant(65.0, "Pink");
            NurseryPlant *aloe = lowMaintenanceFactory->createTree(0.5, 35.0);
            NurseryPlant *baobab = highMaintenanceFactory->createTree(1.2, 120.0);

            // Create containers (FACTORY METHOD pattern)
            Container *roseCrate = crateFactory->createContainer("Wood");
            Container *cherryCrate = crateFactory->createContainer("Cedar Wood");
            Container *aloeCrate = crateFactory->createContainer("Plastic");
            Container *baobabCrate = crateFactory->createContainer("Large Wood");

            // Plant in garden with containers
            nurseryGarden.addPlant(rose, roseCrate);
            nurseryGarden.addPlant(cherry, cherryCrate);
            nurseryGarden.addPlant(aloe, aloeCrate);
            nurseryGarden.addPlant(baobab, baobabCrate);

            // Keep references for growing
            rosesToPlant.push_back(rose);
            cherryBlossomsToPlant.push_back(cherry);
            aloesToPlant.push_back(aloe);
            baobabsToPlant.push_back(baobab);
        }

        cout << "\nGarden status:\n";
        nurseryGarden.displayPlants();
        cout << "Total plants in garden: " << nurseryGarden.getPlantCount() << "\n";

        auto inventory = make_unique<Inventory>();
        auto mediator = make_unique<ConcreteNurseryMediator>();
        mediator->setInventory(inventory.get());

        // Create staff members
        auto expert = make_unique<PlantExpert>(inventory.get(), "Dr. Ngwenya");
        auto cashier = make_unique<Cashier>(inventory.get(), "Thandah", &nurseryGarden);
        auto manager = make_unique<Manager>(inventory.get(), "Ms. H", &nurseryGarden);
        auto nurse = make_unique<Nurse>(inventory.get(), "Kyle");

        // Register staff with mediator
        mediator->addStaff(expert.get());
        mediator->addStaff(cashier.get());
        mediator->addStaff(manager.get());
        mediator->addStaff(nurse.get());

        // Create customer
        auto customer = make_unique<Customer>("Akil", mediator.get());
        mediator->addCustomer(customer.get());
        // STEP 3: OBSERVER + STATE + STRATEGY - Grow plants
        cout << "\n--- STEP 3: Growing Plants (Observer + State + Strategy Patterns) ---\n";

        // Attach staff as observers and let plants grow automatically
        cout << "\nGrowing Roses...\n";
        for (auto *rose : rosesToPlant)
        {
            rose->attach(nurse.get());
            rose->attach(expert.get());

            rose->attach(manager.get());
            rose->setWaterlevel(100);
            rose->startGrowing();
        }

        cout << "\nGrowing Cherry Blossoms...\n";
        for (auto *cherry : cherryBlossomsToPlant)
        {
            cherry->attach(nurse.get());
            cherry->attach(expert.get());
            cherry->attach(manager.get());
            cherry->setWaterlevel(100);
            cherry->startGrowing();
        }

        cout << "\nGrowing Aloe...\n";
        for (auto *aloe : aloesToPlant)
        {

            aloe->attach(nurse.get());
            aloe->attach(expert.get());
            aloe->attach(manager.get());

            aloe->setWaterlevel(100);
            aloe->startGrowing();
        }

        cout << "\nGrowing Baobabs...\n";
        for (auto *baobab : baobabsToPlant)
        {
            baobab->attach(nurse.get());
            baobab->attach(expert.get());
            baobab->attach(manager.get());

            baobab->setWaterlevel(100);
            baobab->startGrowing();
        }

        // Verify plants are in mature state (STATE pattern)
        for (auto *plant : rosesToPlant)
        {
            REQUIRE(plant->getStateName() == "Mature");
        }
        for (auto *plant : cherryBlossomsToPlant)
        {
            REQUIRE(plant->getStateName() == "Mature");
        }
        for (auto *plant : aloesToPlant)
        {
            REQUIRE(plant->getStateName() == "Mature");
        }
        for (auto *plant : baobabsToPlant)
        {
            REQUIRE(plant->getStateName() == "Mature");
        }

        // Verify inventory was populated by observers
        cout << "\nVerifying inventory was populated by observers...\n";
        inventory->displayInventory();

        REQUIRE(inventory->hasStock("Rose", 3));
        REQUIRE(inventory->hasStock("Cherry Blossom", 3));
        REQUIRE(inventory->hasStock("Aloe", 3));
        REQUIRE(inventory->hasStock("Baobab", 3));

        // ============================================================================
        // STEP 3: MEDIATOR - Customer browses and requests advice
        // ============================================================================

        cout << "\n--- STEP 3: Customer Interaction (Mediator Pattern) ---\n";

        customer->browsePlants();
        customer->requestAdvice("low-maintainance");
        customer->requestAdvice("high-maintainance");

        // ============================================================================
        // STEP 4: COMPOSITE + PROTOTYPE - Create bulk order
        // ============================================================================

        cout << "\n--- STEP 4: Creating Bulk Order (Composite + Prototype Patterns) ---\n";

        // Customer purchases one of each type (from inventory)
        cout << "\nCustomer purchasing plants...\n";
        customer->purchasePlant("Rose");
        customer->purchasePlant("Cherry Blossom");
        customer->purchasePlant("Aloe");
        customer->purchasePlant("Baobab");

        // Get the purchased plants from inventory
        NurseryPlant *purchasedRose = inventory->previewPlantForSale("Rose");
        NurseryPlant *purchasedCherry = inventory->previewPlantForSale("Cherry Blossom");
        NurseryPlant *purchasedAloe = inventory->previewPlantForSale("Aloe");
        NurseryPlant *purchasedBaobab = inventory->previewPlantForSale("Baobab");

        REQUIRE(purchasedRose != nullptr);
        REQUIRE(purchasedCherry != nullptr);
        REQUIRE(purchasedAloe != nullptr);
        REQUIRE(purchasedBaobab != nullptr);

        
        // ============================================================================
        // STEP 5: DECORATOR - Add gift wrap and bow to each plant
        // ============================================================================

        cout << "\n--- STEP 5: Decorating Plants (Decorator Pattern) ---\n";

        // Apply decorators to each plant
        NurseryPlant *decoratedRose = new BowDecorator(new GiftWrap(purchasedRose));
        NurseryPlant *decoratedCherry = new BowDecorator(new GiftWrap(purchasedCherry));
        NurseryPlant *decoratedAloe = new BowDecorator(new GiftWrap(purchasedAloe));
        NurseryPlant *decoratedBaobab = new BowDecorator(new GiftWrap(purchasedBaobab));

        cout << "Rose decorated cost: R" << dynamic_cast<BowDecorator *>(decoratedRose)->calculateCost() << "\n";
        cout << "Cherry Blossom decorated cost: R" << dynamic_cast<BowDecorator *>(decoratedCherry)->calculateCost() << "\n";
        cout << "Aloe decorated cost: R" << dynamic_cast<BowDecorator *>(decoratedAloe)->calculateCost() << "\n";
        cout << "Baobab decorated cost: R" << dynamic_cast<BowDecorator *>(decoratedBaobab)->calculateCost() << "\n";

        // Verify decoration costs added
        REQUIRE(decoratedRose->getTotal() > 45.0);
        REQUIRE(decoratedCherry->getTotal() > 65.0);

        // Create composite bulk order
        auto bulkOrder = make_unique<BulkOrder>();
        bulkOrder->addOrder(decoratedRose);
        bulkOrder->addOrder(decoratedCherry);
        bulkOrder->addOrder(decoratedAloe);
        bulkOrder->addOrder(decoratedBaobab);

        bulkOrder->setCustomer(customer.get());

        cout << "\nBulk order total: R" << bulkOrder->getTotal() << "\n";

        // ============================================================================
        // STEP 6: ITERATOR - Print order contents for confirmation
        // ============================================================================

        cout << "\n--- STEP 6: Order Confirmation (Iterator Pattern) ---\n";

        unique_ptr<Iterator> orderIterator(bulkOrder->createIterator());
        cout << "\nOrder Contents:\n";
        int itemCount = 0;
        while (orderIterator->hasNext())
        {
            Order *item = orderIterator->next();
            cout << "  - " << item->getID() << ": R" << item->getTotal() << "\n";
            itemCount++;
        }
        REQUIRE(itemCount == 4);

        customer->send("Correct order, I will proceed to checkout.");
}
}
