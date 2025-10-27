#include "NurseryPlant.h"
#include "Rose.h"
#include "Baobab.h"
#include "GiftWrap.h"
#include "BowDecorator.h"
#include "Customer.h"
#include "Cashier.h"
#include "PlantExpert.h"
#include "Nurse.h"
#include "Inventory.h"
#include "ConcreteNurseryMediator.h"
#include <iostream>
#include <string>

int main(){

    NurseryPlant* basicRose = new Rose();
    NurseryPlant* wrappedRose = new GiftWrap(basicRose);
    NurseryPlant* finalRose = new BowDecorator(wrappedRose);  

    std::cout << "Order: " << finalRose->getDescription() << std::endl;
    std::cout << "Total Cost: R" << finalRose->calculateCost() << std::endl;

    NurseryPlant* baobab = new Baobab();
    NurseryPlant* decoratedBaobab = new BowDecorator(baobab);

    std::cout << "Order: " << decoratedBaobab->getDescription() << std::endl;
    std::cout << "Total Cost: R" << decoratedBaobab->calculateCost() << std::endl;

    NurseryPlant* luxuryRose = new BowDecorator(new GiftWrap(new Rose()));

    std::cout << "\n----MEDIATOR PATTERN---" << std::endl;

    ConcreteNurseryMediator mediator;
    
    Customer customer1("John");
    Customer customer2("Sarah");

    Cashier cashier("Alice");
    PlantExpert expert("Dr. Green");
    Nurse nurse("Emily");

    Inventory inventory("Main Inventory");
    

    mediator.addCustomer(&customer1);
    mediator.addCustomer(&customer2);

    mediator.addStaff(&cashier);
    mediator.addStaff(&expert);
    mediator.addStaff(&nurse);

    mediator.setInventory(&inventory);
    
    std::cout << "\n -- Customer Activities --" << std::endl;
    customer1.browsePlants();
    customer2.requestPlantInfo("Rose");
    
    std::cout << "\n--- Staff Activities ---" << std::endl;
    expert.provideCareAdvice("Succulents");
    nurse.waterPlants();
    
    std::cout << "\n--- Sales Process ---" << std::endl;
    customer1.makePurchase("Rose", 50.0);
    cashier.processPayment("John", 50.0);
    cashier.confirmSale("Rose");

    ConcreteNurseryMediator mediator2;
    
    Customer customer("Mike");
    Cashier cashier2("Bob");
    PlantExpert expert2("Dr. Bloom");
    Inventory inventory2("Store Inventory");
    
    mediator2.addCustomer(&customer);

    mediator2.addStaff(&cashier2);
    mediator2.addStaff(&expert2);

    mediator2.setInventory(&inventory2);
    
    std::cout << "\n--- Customer Consultation ---" << std::endl;
    customer.requestPlantInfo("Rose");
    expert2.recommendPlants("sunny garden conditions");
    
    std::cout << "\n--- Creating Decorated Plant Order ---" << std::endl;
    NurseryPlant* finalProduct = new BowDecorator(new GiftWrap(new Rose()));
    
    std::cout << "Custom Order Created: " << finalProduct->getDescription() << std::endl;
    std::cout << "Total Price: R" << finalProduct->calculateCost() << std::endl;
    
    std::cout << "\n--- Processing Sale ---" << std::endl;

    customer.makePurchase("Decorated Rose", finalProduct->calculateCost());
    cashier2.processPayment("Mike", finalProduct->calculateCost());
    cashier2.confirmSale("Decorated Rose");
    cashier2.issueReceipt("Mike");
    
    delete finalProduct;
    
    std::cout << "\n--- Inventory Update ---" << std::endl;
    inventory2.checkStock("Rose");
    inventory2.removePlant("Rose", 1);

    delete finalRose;
    delete decoratedBaobab;
    delete luxuryRose;

    return 0;
}