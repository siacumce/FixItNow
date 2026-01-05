#include "Receptionist.h"

void Receptionist::addID(const string& ID){
    requestID.push_back(ID);
}
double Receptionist::calculateSalary() const{
    return calculateBaseEarnings(); 
}