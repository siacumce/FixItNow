#include "Employee.h"
#include "Utils.h"

int Employee::nextID = 0;

Employee::Employee(string name, string surname, string CNP, string hireDate, string city)
        :name(name), surname(surname), CNP(CNP), employeeID(++nextID), hireDate(hireDate), residenceCity(city){

    if (name.length() < 3 || name.length() > 30) {
        throw invalid_argument("Nume invalid!");
    }
   
    //verify if the person is old enough
    if(!isOldEnough(CNP, hireDate)){
        throw invalid_argument(" Employee is not old enough! ");
    }
    //is the date corect?

    // Verify CNP from Utils
    if(!validateCNP(this->CNP)){
        throw invalid_argument(" CNP invalid! ");
    }
}
double Employee::calculateBaseEarnings() const{
        return BASE_SALARY + getSeniorityBonus() + getTransportBonus();
}
double Employee::getSeniorityBonus() const{
        int years_of_work = calculateYearsSince(Employee::hireDate);

        int nr_of_bonuses = years_of_work/3;
        // for (int i = 0; i < nr_of_bonuses; i++){
        //         bonus += 0.05 * bonus;
        // }
        return nr_of_bonuses * (0.05 * BASE_SALARY);
}
double Employee::getTransportBonus()const {
        if( residenceCity != "Bucuresti" && residenceCity != "Bucharest")
                return 400.0;
        return 0.0;
}
int Employee::getId() const {
    return this->employeeID;
}
string Employee::getCNP() const{
        return this->CNP;
}
string Employee::getSurname() const{
        return surname;
}
void Employee::setSurname(const string& newSurname){
       if (!newSurname.empty()) {
            this->surname = newSurname;
        }
}
void Employee::disp() const{
        cout << "---------------------" << endl;
        cout << " Full Name: " << name << " " << surname << endl;
        cout << " City of Residence: " << residenceCity << endl;
        cout << " [ CNP: " << CNP << " ]" << endl; 
        cout << " [ ID: " << employeeID << " ]" << endl;
}
string Employee::getName() const{
        return name;
}
