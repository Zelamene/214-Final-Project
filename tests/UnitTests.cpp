#define CATCH_CONFIG_MAIN
#include "../catch_amalgamated.hpp"
#include <memory>

#include "../HighMaintenancePlantFactory.h"
#include "../LowMaintenancePlantFactory.h"
#include "../NurseryPlant.h"
#include "../CrateFactory.h"
TEST_CASE("Factory Pattern - Plant and Container Creation", "[factory]")
{
    HighMaintenancePlantFactory highFactory;
    LowMaintenancePlantFactory lowFactory;
    CrateFactory crateFactory;

    auto *cherryBlossom = highFactory.createFloweringPlant(45.0);
    auto *aloe = lowFactory.createTree(0.7, 25.0);
    auto *crate = crateFactory.createContainer("Wood");
    auto *rose = lowFactory.createFloweringPlant(102, "Red");
    auto *baobab = highFactory.createTree(5, 78);

    REQUIRE(cherryBlossom != nullptr);
    REQUIRE(aloe != nullptr);
    REQUIRE(crate != nullptr);
    REQUIRE(crate->getType() == "Crate");
    REQUIRE(cherryBlossom->getColor() == "Pink");
    REQUIRE(aloe->getName() == "Aloe");
    REQUIRE(rose->getColor() == "Red");
    REQUIRE(baobab->getName() == "Baobab");
    REQUIRE(baobab->getHeight() == 5);
}
