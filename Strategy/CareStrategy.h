#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H
#include <vector>
#include <string>
#include <iostream>
#include "NurseryPlant.h"
class CareStrategy {
public:
    virtual void performCare(NurseryPlant& plant) = 0;
    virtual ~CareStrategy() = default;
};

#endif