#  Nursery Management System

## Project Description

A **C++ nursery management system** simulating a realistic plant nursery.
It demonstrates **multiple software design patterns** while managing
plant growth, staff roles, customer orders, inventory, and payments.

---

## Key Features

- **Plant Management:** Multiple plant types (Roses, Cherry Blossoms,
Aloe, Baobab) with growth states
- **Staff System:** Roles like Manager, Cashier, Nurse, and Plant Expert
- **Order Processing:** Complete workflow from browsing to delivery
- **Inventory Tracking:** Real-time stock updates
- **Payment Processing:** Cash, Credit Card, Mobile Payment
- **Dispute Resolution:** Chain of Responsibility for customer issues

---

##  Design Patterns

Demonstrates **13 design patterns** in a realistic workflow:

- **Abstract Factory:** Plant creation
- **Factory Method:** Container creation
- **Prototype:** Order cloning
- **Composite:** Bulk orders
- **Decorator:** Gift wrapping
- **State:** Plant growth stages
- **Strategy:** Payment & plant care strategies
- **Observer:** Staff notifications
- **Mediator:** Communication hub
- **Chain of Responsibility:** Dispute handling
- **Command:** Order operations
- **Iterator:** Traversing bulk orders
- **Template Method:** Slip generation

---

## Project Structure
```
├── *.h # Header files

├── catch_amalgamated.hpp # Catch2 testing framework

├── catch_amalgamated.cpp # Catch2 implementation

├── *.cpp # Implementation files
├── tests/
│ └── UnitTests.cpp # Integration tests

├── Makefile # Build configuration

└── README.md
```
---

## Getting Started

###  Prerequisites

- C++17 compatible compiler
- Make (optional)

---

### Compile & Run

**Using Makefile:**

```bash
make         # Compile
make run     # Run tests
make clean   # Clean build artifacts
```

Or manually:
```bash
g++ -std=c++17 -Wall -Wextra -g -o nursery_test test/UnitTests.cpp
catch_amalgamated.cpp *.cpp -I.
./nursery_test
```
###  Highlights

- Full simulation of plant growth and staff interaction
- Automated inventory and order management
- Payment processing with multiple strategies
- Dispute and refund handling using design patterns
