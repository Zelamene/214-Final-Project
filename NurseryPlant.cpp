#include "NurseryPlant.h"
NurseryPlant::NurseryPlant(const std::string& name, const std::string& maintenanceType)
        : name(name), maintenanceType(maintenanceType) {}

std::string NurseryPlant::getName() const{
    return name;
}
std::string NurseryPlant::getMaintenanceType() const {
    return maintenanceType;
}