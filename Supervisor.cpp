#include "Supervisor.h"

double Supervisor::calculateSalary() const{
    double salary = Employee::calculateBaseEarnings();
    //special Supervisor bonus (%20 of base)
    salary += (0.20 * Employee::BASE_SALARY);
    return salary;
}