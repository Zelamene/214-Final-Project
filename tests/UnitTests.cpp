#define CATCH_CONFIG_MAIN
#include "../catch_amalgamated.hpp"
#include <memory>

#include "../HighMaintenancePlantFactory.h"
#include "../LowMaintenancePlantFactory.h"
#include "../NurseryPlant.h"
#include "../CrateFactory.h"
TEST_CASE("Factory Pattern - Plant and Container Creation", "[factory]") {
    HighMaintenancePlantFactory highFactory;
    LowMaintenancePlantFactory lowFactory;
    CrateFactory crateFactory;

    auto *rose = highFactory.createFloweringPlant(45.0, "Red");
    auto *aloe = lowFactory.createTree(0.7, 25.0);
    auto *crate = crateFactory.createContainer("Wood");

    REQUIRE(rose != nullptr);
    REQUIRE(aloe != nullptr);
    REQUIRE(crate != nullptr);
    REQUIRE(crate->getType() == "Crate");
    REQUIRE(rose->getType() == "FloweringPlant");
    REQUIRE(aloe->getType() == "Tree");
    REQUIRE(rose->getColor() == "Red");
    

}
    
    
