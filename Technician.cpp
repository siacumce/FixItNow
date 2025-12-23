#include "Technician.h"

void Technician::addRepairValue(double value) {
    totalRepairsValue += value;
}

double Technician::calculateSalary() const {
    double base_salary = Employee::calculateSalary();
    //bonus 
    double repairBonus = 0.02 * totalRepairsValue;
    return base_salary + repairBonus;
}

void Technician::addSkill(const string &type, const string &brand) {
    competences.push_back({type, brand});
}

bool Technician::canRepair(const string& type, const string& brand){
    for(const auto& comp : competences){
        if(comp.type == type && comp.brand == brand){
            return true;
        }
    }
    return false;
}