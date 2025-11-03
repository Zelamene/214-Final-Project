#ifndef LOWMAINTENANCEPLANTCARE_H
#define LOWMAINTENANCEPLANTCARE_H

#include "CareStrategy.h"
using namespace std;

/**
 * @class LowMaintenancePlantCare
 * @brief Concrete care strategy for low-maintenance plants.
 *
 * Implements the CareStrategy interface to provide basic care for plants
 * that require minimal attention.
 */
class LowMaintenancePlantCare : public CareStrategy {
public:
    /**
     * @brief Performs care actions on the given plant.
     * @param plant The plant to care for.
     */
    void performCare(NurseryPlant& plant) override;

    /**
     * @brief Destructor.
     */
    virtual ~LowMaintenancePlantCare();
};

#endif
