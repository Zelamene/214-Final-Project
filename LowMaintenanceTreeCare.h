#ifndef LOWMAINTENANCETREECARE_H
#define LOWMAINTENANCETREECARE_H

#include "CareStrategy.h"
using namespace std;

/**
 * @class LowMaintenanceTreeCare
 * @brief Concrete care strategy for low-maintenance trees.
 *
 * Implements the CareStrategy interface to provide simple care for trees
 * that require minimal maintenance.
 */
class LowMaintenanceTreeCare : public CareStrategy
{
public:
    /**
     * @brief Performs care actions on the given tree.
     * @param plant The tree to care for.
     */
    void performCare(NurseryPlant &plant) override;

    /**
     * @brief Destructor.
     */
    virtual ~LowMaintenanceTreeCare();
};

#endif
