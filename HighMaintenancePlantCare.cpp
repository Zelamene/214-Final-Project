#include "HighMaintenancePlantCare.h"

    void HighMaintenancePlantCare:: performCare(NurseryPlant& plant) {
           cout << "Performing high-maintenance care for plant: "
                  << plant.getName() << endl;
        cout << " - Water daily\n - Fertilize weekly\n - Full sunlight\n";
    }

    HighMaintenancePlantCare::~HighMaintenancePlantCare() {}
