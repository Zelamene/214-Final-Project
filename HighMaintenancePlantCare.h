#ifndef HIGHMAINTENANCEPLANTCARE_H
#define HIGHMAINTENANCEPLANTCARE_H

#include "CareStrategy.h"
using namespace std;

/**
 * @class HighMaintenancePlantCare
 * @brief Concrete care strategy for high-maintenance plants.
 *
 * Implements the CareStrategy interface to provide specialized care.
 */
class HighMaintenancePlantCare : public CareStrategy
{
public:
    /**
     * @brief Performs care actions on the given plant.
     * @param plant The plant to care for.
     */
    void performCare(NurseryPlant &plant) override;

    /**
     * @brief Destructor.
     */
    virtual ~HighMaintenancePlantCare();
};

#endif
