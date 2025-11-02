#include "HighMaintenanceTreeCare.h"

    void HighMaintenanceTreeCare:: performCare(NurseryPlant& plant) {
         cout << "Performing high-maintenance care for tree: "
                  << plant.getName() << endl;
        cout << " - Deep watering twice weekly\n - Prune monthly\n - Soil nutrient check\n";
    }

    HighMaintenanceTreeCare::~HighMaintenanceTreeCare() {}
