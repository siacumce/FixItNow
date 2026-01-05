#include "Technician.h"

double Technician::getTotalRepairsValue() const{
    double totalRepairsValue = 0;
    for(const auto& x : repairsValue){
        totalRepairsValue += x;
    }
    return totalRepairsValue;
}
double Technician::getTransportBonus() const{
    return Employee::getTransportBonus();
}
double Technician::calculateSalary() const {
    double base_salary = Employee::calculateBaseEarnings();
    
    //bonus 
    double totalRepairsValue = getTotalRepairsValue();
    double repairBonus = 0.2*totalRepairsValue;
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
string Technician::getRole() const{
    return "Technician";
}

void Technician::disp() const{
    Employee::disp();
    //cout << " [Rol: " << getRole() << " ]" << endl;
}