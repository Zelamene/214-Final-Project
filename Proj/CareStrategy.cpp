#include "CareStrategy.h"

CareStrategy::~CareStrategy() {}

void CareStrategy::performCare(NurseryPlant& plant) {
    // Perform care routine for a specific plant
    std :: cout << "Performing care for " << plant.getName() << std :: endl;
}