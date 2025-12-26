#include "Employee.h"
#include "Utils.h"

int Employee::nextID = 0;

Employee::Employee(string name, string surname, string CNP, const int employeeID, string hireDate, string city)
        :name(name), surname(surname), CNP(CNP), employeeID(++nextID), hireDate(hireDate), residenceCity(city){

    if (name.length() < 3 || name.length() > 30) {
        throw invalid_argument("Nume invalid!");
    }
   
    // Verify CNP from Utils
    if(!validateCNP(CNP)){
        throw invalid_argument("CNP invalid!");
    }
}

double Employee::calculateBaseEarnings() const{
        return BASE_SALARY + getSeniorityBonus() + getTransportBonus();
}
double Employee::getSeniorityBonus() const{
        int years_of_work = calculateYearsSince(Employee::hireDate);

        int nr_of_bonuses = years_of_work/3, bonus = this->BASE_SALARY;
        for (int i = 0; i < nr_of_bonuses; i++){
                bonus += 0.05 * bonus + bonus;
        }
        return bonus;
}

double Employee::getTransportBonus()const {
        if( residenceCity != "Bucuresti" && residenceCity != "Bucharest")
                return 400.0;
        return 0.0;
}

int Employee::getId() const {
    return this->employeeID;
}

void Employee::disp() const {
   // cout << ": " << employeeID << ", Name: " << name << ", Surname: " << surname << ", city: " << residenceCity << endl;
}
