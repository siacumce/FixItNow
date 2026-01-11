#include "Receptionist.h"

double Receptionist::calculateSalary() const{
    return calculateBaseEarnings(); 
}

string Receptionist::getRole() const{
    return "Receptionist";
}

void Receptionist::disp() const{
    Employee::disp();
    cout << " Role: " << getRole() << endl;
    cout << " Current Month Salary: " << calculateSalary() << endl; 
    cout << "---------------------" << endl;
}

void Receptionist::addRequestID(int id) {
        requestID.push_back(id);
}