#include "LowMaintenancePlantCare.h"

    void LowMaintenancePlantCare:: performCare(NurseryPlant& plant) {
        cout << "Performing low-maintenance care for plant: "
                  << plant.getName() << endl;
        cout << " - Water once a week\n - Occasional fertilizer\n - Partial sunlight\n";
    }


    LowMaintenancePlantCare::~LowMaintenancePlantCare() {}