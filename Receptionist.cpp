#include "Receptionist.h"

void Receptionist::addID(const string& ID){
    requestID.push_back(ID);
}
double Receptionist::calculateSalary() const{
    return calculateBaseEarnings(); 
}

string Receptionist::getRole() const{
    return "Receptionist";
}

void Receptionist::disp() const{
    Employee::disp();
    //cout << " [Rol: " << getRole() << " ]" << endl;
}