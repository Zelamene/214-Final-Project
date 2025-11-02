#ifndef HIGHMAINTENANCETREECARE_H
#define HIGHMAINTENANCETREECARE_H

#include "CareStrategy.h"
using namespace std;

/**
 * @class HighMaintenanceTreeCare
 * @brief Concrete care strategy for high-maintenance trees.
 *
 * Implements the CareStrategy interface to provide specialized care for trees
 * that require more attention and maintenance.
 */
class HighMaintenanceTreeCare : public CareStrategy
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
    virtual ~HighMaintenanceTreeCare();
};

#endif
