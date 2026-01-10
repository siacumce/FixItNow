#include "Supervisor.h"

double Supervisor::calculateSalary() const{
    double salary = Employee::calculateBaseEarnings();

    //special Supervisor bonus (%20 of base)
    salary += (0.20 * Employee::BASE_SALARY);
    return salary;
}
string Supervisor::getRole() const {
        return "Supervisor";
}
void Supervisor::disp() const{
    Employee::disp();
    cout << "Role: " << getRole() << endl;
    cout << "Current Month Salary: " << calculateSalary() << endl; 
    cout << "---------------------" << endl;
}
