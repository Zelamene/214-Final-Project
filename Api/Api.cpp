#include "httplib.h"
#include "json.hpp"
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
#include "../Invoker.h"
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <mutex>

using json = nlohmann::json;
using namespace httplib;
using namespace std;

// Global system components with thread safety
unique_ptr<Garden> nurseryGarden;
unique_ptr<Inventory> inventory;
unique_ptr<ConcreteNurseryMediator> mediator;
unique_ptr<PlantExpert> expert;
unique_ptr<Cashier> cashier;
unique_ptr<Manager> manager;
unique_ptr<Nurse> nurse;
unique_ptr<PlantFactory> highMaintenanceFactory;
unique_ptr<PlantFactory> lowMaintenanceFactory;
unique_ptr<ContainerFactory> crateFactory;

map<string, unique_ptr<Customer>> customers;
map<string, unique_ptr<BulkOrder>> activeOrders;
vector<unique_ptr<Order>> completedOrders;

mutex systemMutex;

void initializeSystem() {
    nurseryGarden = make_unique<Garden>();
    highMaintenanceFactory = make_unique<HighMaintenancePlantFactory>();
    lowMaintenanceFactory = make_unique<LowMaintenancePlantFactory>();
    crateFactory = make_unique<CrateFactory>();
    inventory = make_unique<Inventory>();
    mediator = make_unique<ConcreteNurseryMediator>();
    mediator->setInventory(inventory.get());
    
    expert = make_unique<PlantExpert>(inventory.get(), "Dr. Ngwenya");
    cashier = make_unique<Cashier>(inventory.get(), "Thandah", nurseryGarden.get());
    manager = make_unique<Manager>(inventory.get(), "Ms. H", nurseryGarden.get());
    nurse = make_unique<Nurse>(inventory.get(), "Kyle");
    
    mediator->addStaff(expert.get());
    mediator->addStaff(cashier.get());
    mediator->addStaff(manager.get());
    mediator->addStaff(nurse.get());
}

// Helper: Convert inventory to JSON
json inventoryToJson() {
    json items = json::array();
    // You'll need to add a method to get inventory items
    // This is a placeholder structure
    return {
        {"status", "success"},
        {"items", items},
        {"total_plants", nurseryGarden->getPlantCount()}
    };
}

// Helper: Convert order to JSON
json orderToJson(BulkOrder* order) {
    json items = json::array();
    unique_ptr<Iterator> it(order->createIterator());
    while (it->hasNext()) {
        Order* item = it->next();
        items.push_back({
            {"id", item->getID()},
            {"price", item->getTotal()}
        });
    }
    return {
        {"items", items},
        {"total", order->getTotal()}
    };
}

int main() {
    Server svr;
    // Handle all OPTIONS requests for CORS preflight
    // Handle preflight (no headers here)
    svr.Options(R"(.*)", [](const Request&, Response& res) {
        res.status = 200;
    });

    // Global CORS headers for all responses
    svr.set_default_headers({
        {"Access-Control-Allow-Origin", "*"},
        {"Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS"},
        {"Access-Control-Allow-Headers", "Content-Type"}
    });
        

    
    initializeSystem();
    
    cout << "🌱 Nursery Management API Server Starting...\n";
    
    // CORS middleware

    // ==================== HEALTH CHECK ====================
    svr.Get("/api/health", [](const Request&, Response& res) {
        json response = {
            {"status", "healthy"},
            {"service", "Nursery Management API"},
            {"version", "1.0.0"}
        };
        res.set_content(response.dump(), "application/json");
    });
    
    // ==================== PLANTS ENDPOINTS ====================
    
    // POST /api/plants/flower - Add a flowering plant
    svr.Post("/api/plants/flower", [](const Request& req, Response& res) {
        lock_guard<mutex> lock(systemMutex);
        try {
            auto body = json::parse(req.body);
            
            string type = body["type"]; // "low" or "high"
            double price = body["price"];
            string color = body["color"];
            string material = body.value("container", "Wood");
            
            NurseryPlant* plant = nullptr;
            if (type == "low") {
                plant = lowMaintenanceFactory->createFloweringPlant(price, color);
            } else {
                plant = highMaintenanceFactory->createFloweringPlant(price, color);
            }
            
            Container* container = crateFactory->createContainer(material);
            nurseryGarden->addPlant(plant, container);
            
            res.set_content(json({
                {"status", "success"},
                {"message", "Flowering plant added"},
                {"plant_type", type},
                {"color", color}
            }).dump(), "application/json");
        } catch (exception& e) {
            res.status = 400;
            res.set_content(json({
                {"status", "error"},
                {"message", e.what()}
            }).dump(), "application/json");
        }
    });
    
    // POST /api/plants/tree - Add a tree
    svr.Post("/api/plants/tree", [](const Request& req, Response& res) {
        lock_guard<mutex> lock(systemMutex);
        try {
            auto body = json::parse(req.body);
            
            string type = body["type"]; // "low" or "high"
            double height = body["height"];
            double price = body["price"];
            string material = body.value("container", "Plastic");
            
            NurseryPlant* plant = nullptr;
            if (type == "low") {
                plant = lowMaintenanceFactory->createTree(height, price);
            } else {
                plant = highMaintenanceFactory->createTree(height, price);
            }
            
            Container* container = crateFactory->createContainer(material);
            nurseryGarden->addPlant(plant, container);
            
            res.set_content(json({
                {"status", "success"},
                {"message", "Tree added"},
                {"plant_type", type},
                {"height", height}
            }).dump(), "application/json");
        } catch (exception& e) {
            res.status = 400;
            res.set_content(json({
                {"status", "error"},
                {"message", e.what()}
            }).dump(), "application/json");
        }
    });
    
    // POST /api/plants/grow - Grow all plants to maturity
    svr.Post("/api/plants/grow", [](const Request&, Response& res) {
        lock_guard<mutex> lock(systemMutex);
        try {
            auto plants = nurseryGarden->getAllPlants();
            int count = 0;
            
            for (auto* plant : plants) {
                plant->attach(nurse.get());
                plant->attach(expert.get());
                plant->attach(manager.get());
                plant->setWaterlevel(100);
                plant->startGrowing();
                count++;
            }
            
            res.set_content(json({
                {"status", "success"},
                {"message", "Plants grown to maturity"},
                {"plants_grown", count}
            }).dump(), "application/json");
        } catch (exception& e) {
            res.status = 500;
            res.set_content(json({
                {"status", "error"},
                {"message", e.what()}
            }).dump(), "application/json");
        }
    });
    
    // GET /api/plants - Get all plants in garden
    svr.Get("/api/plants", [](const Request&, Response& res) {
        lock_guard<mutex> lock(systemMutex);
        try {
            res.set_content(json({
                {"status", "success"},
                {"plant_count", nurseryGarden->getPlantCount()}
            }).dump(), "application/json");
        } catch (exception& e) {
            res.status = 500;
            res.set_content(json({
                {"status", "error"},
                {"message", e.what()}
            }).dump(), "application/json");
        }
    });
    
    // ==================== INVENTORY ENDPOINTS ====================
    
    // GET /api/inventory - Get inventory status
    svr.Get("/api/inventory", [](const Request&, Response& res) {
        lock_guard<mutex> lock(systemMutex);
        try {
            res.set_content(inventoryToJson().dump(), "application/json");
        } catch (exception& e) {
            res.status = 500;
            res.set_content(json({
                {"status", "error"},
                {"message", e.what()}
            }).dump(), "application/json");
        }
    });
    
    // ==================== CUSTOMER ENDPOINTS ====================
    
    // POST /api/customers - Register a new customer
    svr.Post("/api/customers", [](const Request& req, Response& res) {
        lock_guard<mutex> lock(systemMutex);
        try {
            auto body = json::parse(req.body);
            string name = body["name"];
            string customerId = body.value("id", name);
            
            auto customer = make_unique<Customer>(name, mediator.get());
            mediator->addCustomer(customer.get());
            customers[customerId] = move(customer);
            
            res.set_content(json({
                {"status", "success"},
                {"message", "Customer registered"},
                {"customer_id", customerId},
                {"name", name}
            }).dump(), "application/json");
        } catch (exception& e) {
            res.status = 400;
            res.set_content(json({
                {"status", "error"},
                {"message", e.what()}
            }).dump(), "application/json");
        }
    });
    
    // ==================== ORDER ENDPOINTS ====================
    
    // POST /api/orders - Create new order
    svr.Post("/api/orders", [](const Request& req, Response& res) {
        lock_guard<mutex> lock(systemMutex);
        try {
            auto body = json::parse(req.body);
            string customerId = body["customer_id"];
            
            if (customers.find(customerId) == customers.end()) {
                res.status = 404;
                res.set_content(json({
                    {"status", "error"},
                    {"message", "Customer not found"}
                }).dump(), "application/json");
                return;
            }
            
            auto order = make_unique<BulkOrder>();
            order->setCustomer(customers[customerId].get());
            string orderId = customerId + "_order";
            activeOrders[orderId] = move(order);
            
            res.set_content(json({
                {"status", "success"},
                {"message", "Order created"},
                {"order_id", orderId}
            }).dump(), "application/json");
        } catch (exception& e) {
            res.status = 400;
            res.set_content(json({
                {"status", "error"},
                {"message", e.what()}
            }).dump(), "application/json");
        }
    });
    
    // POST /api/orders/:id/items - Add item to order
    svr.Post(R"(/api/orders/([^/]+)/items)", [](const Request& req, Response& res) {
        lock_guard<mutex> lock(systemMutex);
        try {
            string orderId = req.matches[1];
            auto body = json::parse(req.body);
            string plantName = body["plant_name"];
            bool decorate = body.value("decorate", false);
            
            if (activeOrders.find(orderId) == activeOrders.end()) {
                res.status = 404;
                res.set_content(json({
                    {"status", "error"},
                    {"message", "Order not found"}
                }).dump(), "application/json");
                return;
            }
            
            if (!inventory->hasStock(plantName, 1)) {
                res.status = 400;
                res.set_content(json({
                    {"status", "error"},
                    {"message", "Plant not in stock"}
                }).dump(), "application/json");
                return;
            }
            
            NurseryPlant* plant = inventory->previewPlantForSale(plantName);
            if (plant) {
                if (decorate) {
                    plant = new BowDecorator(new GiftWrap(plant));
                }
                activeOrders[orderId]->addOrder(plant);
                
                res.set_content(json({
                    {"status", "success"},
                    {"message", "Item added to order"},
                    {"plant", plantName},
                    {"price", plant->getTotal()}
                }).dump(), "application/json");
            }
        } catch (exception& e) {
            res.status = 400;
            res.set_content(json({
                {"status", "error"},
                {"message", e.what()}
            }).dump(), "application/json");
        }
    });
    
    // GET /api/orders/:id
    svr.Get(R"(/api/orders/([^/]+))", [](const Request& req, Response& res) {
        lock_guard<mutex> lock(systemMutex);
        try {
            string orderId = req.matches[1];
            
            if (activeOrders.find(orderId) == activeOrders.end()) {
                res.status = 404;
                res.set_content(json({
                    {"status", "error"},
                    {"message", "Order not found"}
                }).dump(), "application/json");
                return;
            }
            
            json response = orderToJson(activeOrders[orderId].get());
            response["status"] = "success";
            response["order_id"] = orderId;
            
            res.set_content(response.dump(), "application/json");
        } catch (exception& e) {
            res.status = 500;
            res.set_content(json({
                {"status", "error"},
                {"message", e.what()}
            }).dump(), "application/json");
        }
    });
    
    // POST /api/orders/:id/checkout
    svr.Post(R"(/api/orders/([^/]+)/checkout)", [](const Request& req, Response& res) {
        lock_guard<mutex> lock(systemMutex);
        try {
            string orderId = req.matches[1];
            auto body = json::parse(req.body);
            
            if (activeOrders.find(orderId) == activeOrders.end()) {
                res.status = 404;
                res.set_content(json({
                    {"status", "error"},
                    {"message", "Order not found"}
                }).dump(), "application/json");
                return;
            }
            
            BulkOrder* order = activeOrders[orderId].get();
            string paymentType = body["payment_type"];
            
            unique_ptr<PaymentStrategy> payment;
            
            if (paymentType == "cash") {
                double tendered = body["amount_tendered"];
                payment = make_unique<CashPayment>(tendered);
            } else if (paymentType == "card") {
                string cardNum = body["card_number"];
                string expiry = body["expiry"];
                payment = make_unique<CreditCardPayment>(cardNum, expiry);
            } else if (paymentType == "mobile") {
                string phone = body["phone"];
                string provider = body["provider"];
                payment = make_unique<MobilePayment>(phone, provider);
            }
            
            cashier->setPaymentStrategy(payment.get());
            
            if (payment->processPayment(order->getTotal())) {
                Invoker orderManager;
                PackageOrderCommand packageCmd(order);
                DeliverOrderCommand deliverCmd(order);
                
                orderManager.addCommand(&packageCmd);
                orderManager.addCommand(&deliverCmd);
                orderManager.processCommands();
                
                completedOrders.push_back(unique_ptr<Order>(order->clone()));
                activeOrders.erase(orderId);
                
                res.set_content(json({
                    {"status", "success"},
                    {"message", "Order completed"},
                    {"total", order->getTotal()}
                }).dump(), "application/json");
            } else {
                res.status = 400;
                res.set_content(json({
                    {"status", "error"},
                    {"message", "Payment failed"}
                }).dump(), "application/json");
            }
        } catch (exception& e) {
            res.status = 400;
            res.set_content(json({
                {"status", "error"},
                {"message", e.what()}
            }).dump(), "application/json");
        }
    });
    
    // POST /api/complaints
    svr.Post("/api/complaints", [](const Request& req, Response& res) {
        lock_guard<mutex> lock(systemMutex);
        try {
            auto body = json::parse(req.body);
            string customerId = body["customer_id"];
            string complaint = body["complaint"];
            
            if (customers.find(customerId) == customers.end()) {
                res.status = 404;
                res.set_content(json({
                    {"status", "error"},
                    {"message", "Customer not found"}
                }).dump(), "application/json");
                return;
            }
            
            customers[customerId]->send("Complaint: " + complaint);
            
            bool isRefund = complaint.find("refund") != string::npos || 
                           complaint.find("Refund") != string::npos;
            
            json response = {
                {"status", "success"},
                {"message", "Complaint filed"},
                {"refund_requested", isRefund}
            };
            
            if (isRefund && !completedOrders.empty()) {
                Order* lastOrder = completedOrders.back().get();
                unique_ptr<Order> refundOrder(lastOrder->clone());
                
                RefundSlip refundSlip(refundOrder.get());
                Issue refundIssue("Refund", "Processing refund for order", refundOrder.get());
                
                CashierHandler cashierHandler;
                cashierHandler.setSlipGenerator(&refundSlip);
                ManagerHandler managerHandler;
                cashierHandler.setNext(&managerHandler);
                cashierHandler.handle(&refundIssue);
                
                response["refund_processed"] = true;
                response["refund_amount"] = refundOrder->getTotal();
            }
            
            res.set_content(response.dump(), "application/json");
        } catch (exception& e) {
            res.status = 400;
            res.set_content(json({
                {"status", "error"},
                {"message", e.what()}
            }).dump(), "application/json");
        }
    });
    
    // ==================== DEMO ENDPOINT ====================
    
    // POST /api/demo/quick
    svr.Post("/api/demo/quick", [](const Request&, Response& res) {
        lock_guard<mutex> lock(systemMutex);
        try {
            for (int i = 0; i < 2; i++) {
                NurseryPlant* rose = lowMaintenanceFactory->createFloweringPlant(45.0, "Red");
                NurseryPlant* cherry = highMaintenanceFactory->createFloweringPlant(65.0, "Pink");
                NurseryPlant* aloe = lowMaintenanceFactory->createTree(0.5, 35.0);
                NurseryPlant* baobab = highMaintenanceFactory->createTree(1.2, 120.0);
                
                Container* c1 = crateFactory->createContainer("Wood");
                Container* c2 = crateFactory->createContainer("Cedar");
                Container* c3 = crateFactory->createContainer("Plastic");
                Container* c4 = crateFactory->createContainer("Large Wood");
                
                nurseryGarden->addPlant(rose, c1);
                nurseryGarden->addPlant(cherry, c2);
                nurseryGarden->addPlant(aloe, c3);
                nurseryGarden->addPlant(baobab, c4);
            }
            
            auto plants = nurseryGarden->getAllPlants();
            for (auto* plant : plants) {
                plant->attach(nurse.get());
                plant->attach(expert.get());
                plant->attach(manager.get());
                plant->setWaterlevel(100);
                plant->startGrowing();
            }
            
            res.set_content(json({
                {"status", "success"},
                {"message", "Demo completed"},
                {"plants_added", 8},
                {"total_plants", nurseryGarden->getPlantCount()}
            }).dump(), "application/json");
        } catch (exception& e) {
            res.status = 500;
            res.set_content(json({
                {"status", "error"},
                {"message", e.what()}
            }).dump(), "application/json");
        }
    });
    
    cout << " Server running on http://localhost:8080\n";
    cout << " API Documentation:\n";
    cout << "  GET  /api/health - Health check\n";
    cout << "  POST /api/plants/flower - Add flowering plant\n";
    cout << "  POST /api/plants/tree - Add tree\n";
    cout << "  POST /api/plants/grow - Grow all plants\n";
    cout << "  GET  /api/inventory - Get inventory\n";
    cout << "  POST /api/customers - Register customer\n";
    cout << "  POST /api/orders - Create order\n";
    cout << "  POST /api/orders/:id/items - Add item to order\n";
    cout << "  GET  /api/orders/:id - Get order details\n";
    cout << "  POST /api/orders/:id/checkout - Checkout\n";
    cout << "  POST /api/complaints - File complaint\n";
    cout << "  POST /api/demo/quick - Run demo\n";
    
    svr.listen("0.0.0.0", 8080);
    
    return 0;
}