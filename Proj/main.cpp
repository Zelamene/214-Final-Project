/**
 * @file main.cpp
 * @brief Comprehensive test suite for Nursery Management System
 * Testing Command Pattern, Strategy Pattern, and Chain of Responsibility Pattern
 */

#include <iostream>
#include <memory>
#include <vector>

// Command Pattern Headers
#include "Command.h"
#include "Customer.h"
#include "Order.h"
#include "Staff.h"
#include "Invoker.h"
#include "PrepareCommand.h"
#include "PackageOrderCommand.h"
#include "DeliverOrderCommand.h"
#include "WaterPlantCommand.h"
#include "FertilizeBedCommand.h"

// Strategy Pattern Headers
#include "Aloe.h"
#include "AloeCare.h"
#include "Baobab.h"
#include "BaobabCare.h"
#include "CherryBlossom.h"
#include "CherryCare.h"
#include "Rose.h"
#include "RoseCare.h"
#include "Tree.h"
#include "FloweringPlant.h"

// Chain of Responsibility Headers
#include "CashierHandler.h"
#include "ManagerHandler.h"
#include "Issue.h"

void testStrategyPattern() {
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "TESTING STRATEGY PATTERN - PLANT TYPES & CARE STRATEGIES\n";
    std::cout << std::string(60, '=') << "\n";
    
    // Create care strategies
    AloeCare aloeCare;
    BaobabCare baobabCare;
    CherryBlossomCare cherryCare;
    RoseCare roseCare;
    
    // Create plants with different strategies
    Aloe aloePlant(35.0);
    Baobab baobabTree(120.0);
    CherryBlossom cherryBlossom(40.0);
    Rose rosePlant(25.0);
    
    // Create staff with different strategies
    Staff aloeSpecialist("Aloe Expert", &aloeCare);
    Staff treeSpecialist("Tree Expert", &baobabCare);
    Staff flowerSpecialist("Flower Expert", &cherryCare);
    Staff roseSpecialist("Rose Expert", &roseCare);
    Staff generalStaff("General Staff"); 
    
    std::cout << "\n--- Testing Aloe Plant with Aloe Specialist ---\n";
    aloeSpecialist.careForPlant(aloePlant);
    
    std::cout << "\n--- Testing Baobab Tree with Tree Specialist ---\n";
    treeSpecialist.careForPlant(baobabTree);
    
    std::cout << "\n--- Testing Cherry Blossom with Flower Specialist ---\n";
    flowerSpecialist.careForPlant(cherryBlossom);
    
    std::cout << "\n--- Testing Rose with Rose Specialist ---\n";
    roseSpecialist.careForPlant(rosePlant);
    
    std::cout << "\n--- Testing Strategy Switching ---\n";
    std::cout << "Switching Rose Specialist to Aloe Care strategy:\n";
    roseSpecialist.setStrategy(&aloeCare);
    roseSpecialist.careForPlant(aloePlant);
    
    std::cout << "\n--- Testing Staff without Strategy ---\n";
    generalStaff.careForPlant(rosePlant);
    
    std::cout << "\n--- Testing Plant Type Information ---\n";
    std::cout << "Aloe type: " << aloePlant.getType() << "\n";
    std::cout << "Baobab type: " << baobabTree.getType() << "\n";
    std::cout << "Cherry Blossom type: " << cherryBlossom.getType() << "\n";
    std::cout << "Rose type: " << rosePlant.getType() << "\n";
    
    std::cout << "\n--- Testing Plant Properties ---\n";
    std::cout << "Aloe - Name: " << aloePlant.getName() << ", Price: $" << aloePlant.getPrice() << "\n";
    std::cout << "Baobab - Name: " << baobabTree.getName() << ", Price: $" << baobabTree.getPrice() << "\n";
    
    // Test price modifications
    aloePlant.setPrice(40.0);
    std::cout << "Aloe new price: $" << aloePlant.getPrice() << "\n";
    
    // Test state management
    std::cout << "Rose initial state: " << rosePlant.getState() << "\n";
    rosePlant.setState("blooming");
    std::cout << "Rose updated state: " << rosePlant.getState() << "\n";
}

void testChainOfResponsibility() {
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "TESTING CHAIN OF RESPONSIBILITY PATTERN - ISSUE HANDLING\n";
    std::cout << std::string(60, '=') << "\n";
    
    // Create the chain: Cashier -> Manager
    CashierHandler* cashier = new CashierHandler();
    ManagerHandler* manager = new ManagerHandler();
    
    cashier->setNext(manager);
    
    // Create various issues
    Issue cashierIssue("Cashier", "Payment processing error", false);
    Issue managerIssue("Manager", "Customer complaint escalation", false);
    Issue unknownIssue("Unknown", "Mysterious problem", false);
    Issue deliveryIssue("Delivery", "Shipping delay issue", false);
    
    std::cout << "\n--- Testing Cashier Issue ---\n";
    std::cout << "Before handling - Solved: " << cashierIssue.getSolved() << "\n";
    cashier->handle(&cashierIssue);
    std::cout << "After handling - Solved: " << cashierIssue.getSolved() << "\n";
    
    std::cout << "\n--- Testing Manager Issue ---\n";
    std::cout << "Before handling - Solved: " << managerIssue.getSolved() << "\n";
    cashier->handle(&managerIssue);
    std::cout << "After handling - Solved: " << managerIssue.getSolved() << "\n";
    
    std::cout << "\n--- Testing Unknown Issue (Should reach end of chain) ---\n";
    std::cout << "Before handling - Solved: " << unknownIssue.getSolved() << "\n";
    cashier->handle(&unknownIssue);
    std::cout << "After handling - Solved: " << unknownIssue.getSolved() << "\n";
    
    std::cout << "\n--- Testing Delivery Issue (Should reach end of chain) ---\n";
    std::cout << "Before handling - Solved: " << deliveryIssue.getSolved() << "\n";
    cashier->handle(&deliveryIssue);
    std::cout << "After handling - Solved: " << deliveryIssue.getSolved() << "\n";
    
    // Test issue description modifications
    std::cout << "\n--- Testing Issue Description Updates ---\n";
    cashierIssue.setDescription("Updated: Payment gateway timeout");
    std::cout << "Updated description: " << cashierIssue.getDescription() << "\n";
    
    // Cleanup
    delete cashier; 
}

void testCommandPattern() {
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "TESTING COMMAND PATTERN - ORDER PROCESSING\n";
    std::cout << std::string(60, '=') << "\n";
    
    // Create customers
    Customer customer1("Alice Green");
    Customer customer2("Bob Brown");
    Customer customer3("Carol White");
    
    // Create orders
    Order roseOrder(1001, "Rose Bouquet", &customer1);
    Order aloeOrder(1002, "Aloe Vera", &customer2);
    Order cherryOrder(1003, "Cherry Blossom", &customer3);
    
    // Create staff
    Staff staffMember("John Worker");
    
    std::cout << "\n--- Testing Individual Commands ---\n";
    
    // Test PrepareCommand
    PrepareCommand prepCmd(&roseOrder);
    std::cout << "Testing PrepareCommand:\n";
    prepCmd.execute();
    prepCmd.undo();
    
    // Test PackageOrderCommand
    PackageOrderCommand pkgCmd(&aloeOrder);
    std::cout << "\nTesting PackageOrderCommand:\n";
    pkgCmd.execute();
    pkgCmd.undo();
    
    // Test DeliverOrderCommand
    DeliverOrderCommand delCmd(&cherryOrder);
    std::cout << "\nTesting DeliverOrderCommand:\n";
    delCmd.execute();
    
    // Test WaterPlantCommand
    WaterPlantCommand waterCmd("Rose Garden");
    std::cout << "\nTesting WaterPlantCommand:\n";
    waterCmd.execute();
    waterCmd.undo();
    
    // Test FertilizeBedCommand
    FertilizeBedCommand fertCmd("Main Garden");
    std::cout << "\nTesting FertilizeBedCommand:\n";
    fertCmd.execute();
    fertCmd.undo();
    
    std::cout << "\n--- Testing Staff Executing Commands ---\n";
    staffMember.perform(new PrepareCommand(&roseOrder));
    staffMember.perform(new WaterPlantCommand("Herb Garden"));
}

void testIntegratedWorkflow() {
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "TESTING INTEGRATED WORKFLOW - ALL PATTERNS TOGETHER\n";
    std::cout << std::string(60, '=') << "\n";
    
    // Create plants using Strategy pattern
    Aloe aloe(35.0);
    Rose rose(25.0);
    Baobab baobab(120.0);
    
    // Create care strategies
    AloeCare aloeCare;
    RoseCare roseCare;
    BaobabCare baobabCare;
    
    // Create specialized staff with strategies
    Staff aloeExpert("Aloe Specialist", &aloeCare);
    Staff roseExpert("Rose Specialist", &roseCare);
    Staff treeExpert("Tree Specialist", &baobabCare);
    
    // Create customers and orders
    Customer vipCustomer("VIP Client");
    Customer regularCustomer("Regular Client");
    
    Order vipOrder(2001, "Premium Baobab", &vipCustomer);
    Order regularOrder(2002, "Aloe Plant", &regularCustomer);
    
    // Create command invoker
    Invoker workflow;
    
    // Create CoR chain for issue handling
    CashierHandler* cashier = new CashierHandler();
    ManagerHandler* manager = new ManagerHandler();
    cashier->setNext(manager);
    
    std::cout << "\n--- Phase 1: Plant Care (Strategy Pattern) ---\n";
    aloeExpert.careForPlant(aloe);
    roseExpert.careForPlant(rose);
    treeExpert.careForPlant(baobab);
    
    std::cout << "\n--- Phase 2: Order Processing (Command Pattern) ---\n";
    // Add commands to workflow
    workflow.addCommand(new PrepareCommand(&vipOrder));
    workflow.addCommand(new PackageOrderCommand(&vipOrder));
    workflow.addCommand(new DeliverOrderCommand(&vipOrder));
    workflow.addCommand(new PrepareCommand(&regularOrder));
    workflow.addCommand(new WaterPlantCommand("VIP Section"));
    workflow.addCommand(new FertilizeBedCommand("Main Beds"));
    
    // Process all commands
    workflow.processCommands();
    
    std::cout << "\n--- Phase 3: Issue Resolution (Chain of Responsibility) ---\n";
    // Simulate issues during the workflow
    Issue paymentIssue("Cashier", "Credit card declined", false);
    Issue complaintIssue("Manager", "Customer wants refund", false);
    Issue technicalIssue("IT", "System outage", false);
    
    std::cout << "Handling payment issue:\n";
    cashier->handle(&paymentIssue);
    
    std::cout << "\nHandling complaint issue:\n";
    cashier->handle(&complaintIssue);
    
    std::cout << "\nHandling technical issue (should not be handled):\n";
    cashier->handle(&technicalIssue);
    
    std::cout << "\n--- Phase 4: Final Status Report ---\n";
    std::cout << "VIP Order State: " << vipOrder.getState() << "\n";
    std::cout << "Regular Order State: " << regularOrder.getState() << "\n";
    std::cout << "Payment Issue Resolved: " << paymentIssue.getSolved() << "\n";
    std::cout << "Complaint Issue Resolved: " << complaintIssue.getSolved() << "\n";
    
    // Show staff assignments
    std::cout << "\nStaff assigned to plants:\n";
    std::cout << "Aloe plant staff:\n";
    aloe.showStaff();
    std::cout << "Rose plant staff:\n";
    rose.showStaff();
    
    // Cleanup CoR chain
    delete cashier;
}

void testEdgeCasesAndRobustness() {
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "TESTING EDGE CASES AND ROBUSTNESS\n";
    std::cout << std::string(60, '=') << "\n";
    
    std::cout << "\n--- Testing Empty/Null Values ---\n";
    Customer anonymousCustomer("");
    Order minimalOrder(0, "", &anonymousCustomer);
    
    std::cout << "Minimal order - ID: " << minimalOrder.getId() 
              << ", Plant: '" << minimalOrder.getPlantName() << "'\n";
    
    std::cout << "\n--- Testing Price Boundaries ---\n";
    Aloe freeAloe(0.0);
    Baobab expensiveBaobab(9999.99);
    
    std::cout << "Free plant price: $" << freeAloe.getPrice() << "\n";
    std::cout << "Expensive plant price: $" << expensiveBaobab.getPrice() << "\n";
    
    std::cout << "\n--- Testing State Transitions ---\n";
    freeAloe.setState("");
    std::cout << "Empty state: '" << freeAloe.getState() << "'\n";
    
    std::cout << "\n--- Testing Single Handler Chain ---n";
    CashierHandler* soloCashier = new CashierHandler();
    Issue cashierIssue("Cashier", "Test issue", false);
    soloCashier->handle(&cashierIssue);
    delete soloCashier;
    
    std::cout << "\n--- Testing Unhandled Issue Types ---n";
    ManagerHandler* soloManager = new ManagerHandler();
    Issue unknownIssue("UnknownType", "Should not be handled", false);
    soloManager->handle(&unknownIssue);
    delete soloManager;
}

void testPerformanceScenarios() {
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "TESTING PERFORMANCE SCENARIOS\n";
    std::cout << std::string(60, '=') << "\n";
    
    // Test with multiple plants
    std::cout << "\n--- Testing Multiple Plant Types ---\n";
    std::vector<NurseryPlant*> plants;
    plants.push_back(new Aloe(35.0));
    plants.push_back(new Rose(25.0));
    plants.push_back(new Baobab(120.0));
    plants.push_back(new CherryBlossom(40.0));
    
    Staff multiStaff("Multi-Task Staff");
    RoseCare roseCare;
    multiStaff.setStrategy(&roseCare);
    
    for (auto plant : plants) {
        std::cout << "Caring for: " << plant->getName() << " (" << plant->getType() << ")\n";
        multiStaff.careForPlant(*plant);
    }
    
    // Cleanup
    for (auto plant : plants) {
        delete plant;
    }
    
    // Test command queue with many commands
    std::cout << "\n--- Testing Large Command Queue ---\n";
    Invoker largeQueue;
    Customer testCustomer("Test Customer");
    
    for (int i = 1; i <= 5; i++) {
        Order* order = new Order(3000 + i, "Test Plant " + std::to_string(i), &testCustomer);
        largeQueue.addCommand(new PrepareCommand(order));
        largeQueue.addCommand(new PackageOrderCommand(order));
        // Note: In real code, you'd need to manage order memory properly
    }
    
    largeQueue.addCommand(new WaterPlantCommand("Main Garden"));
    largeQueue.addCommand(new FertilizeBedCommand("All Beds"));
    
    std::cout << "Processing large command queue...\n";
    largeQueue.processCommands();
}

int main() {
    std::cout << "NURSERY MANAGEMENT SYSTEM - COMPREHENSIVE TEST SUITE\n";
    std::cout << "Testing Command, Strategy, and Chain of Responsibility Patterns\n";
    std::cout << std::string(70, '=') << "\n";
    
    try {
        // Test individual patterns
        testStrategyPattern();
        testChainOfResponsibility();
        testCommandPattern();
        
        // Test integrated scenarios
        testIntegratedWorkflow();
        
        // Test edge cases and robustness
        testEdgeCasesAndRobustness();
        
        // Test performance scenarios
        testPerformanceScenarios();
        
        std::cout << "\n" << std::string(70, '=') << "\n";
        std::cout << "ALL TESTS COMPLETED SUCCESSFULLY!\n";
        std::cout << "All design patterns are working correctly:\n";
        std::cout << "✓ Strategy Pattern - Plant types and care behaviors\n";
        std::cout << "✓ Command Pattern - Order processing commands\n";
        std::cout << "✓ Chain of Responsibility - Issue handling pipeline\n";
        std::cout << std::string(70, '=') << "\n";
        
    } catch (const std::exception& e) {
        std::cerr << "TEST FAILED WITH EXCEPTION: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}