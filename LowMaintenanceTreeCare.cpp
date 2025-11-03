#include "LowMaintenanceTreeCare.h"

    void LowMaintenanceTreeCare:: performCare(NurseryPlant& plant) {
        cout << "Performing low-maintenance care for tree: "
                  << plant.getName() << endl;
        cout << " - Deep watering every 2 weeks\n - Minimal pruning\n";
    }

    LowMaintenanceTreeCare::~LowMaintenanceTreeCare() {}