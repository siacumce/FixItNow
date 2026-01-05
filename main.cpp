#include <iostream>
#include <ctime>
#include "Service.h"
using namespace std;

void displayMenu(){
    cout << "\nHello boss! " << "What would you like to do today ? (choose your weapon 1-6)\n";
    cout <<" 1. Add employee;\n";
    cout <<" 2. Modify surname of employee;\n";
    cout <<" 3. Delete employee;\n";
    cout <<" 4. Search employee by CNP and display data;\n";
    cout <<" 5. Calculate salary;\n";
    cout <<" 6. Display list of employees;\n";
    cout <<" 0. Exit\n";
}


int main(){

    Service *s = Service::getInstance();

    cout << "Let's create our service! Loading database...";
    s->loadEmployeesFromFile("./tests/employee_init.csv");

    displayMenu();
    int option = -1;
    while(option){

        cout <<" Your option: "; cin >> option;

        switch (option)
        {
        case 1:{
            string type, name, surname, city, cnp, hireDate;
            cout << "Role (Supervisor, Technician, Receptionist): "; cin >> type;
            cout << "Name: "; cin >> name;
            cout << "Surname: "; cin >> surname;
            cout << "City of provence: "; cin >> city;
            cout << "CNP: "; cin >> cnp;
            cout << "Hire date(DD.MM.YYYY): " ; cin >> hireDate;
            s -> hireEmployee(name, surname, cnp, hireDate, city, type);
            break;
        }
        case 2:{
            string newSurname;
            int id;
            cout << "Search by ID";  cin >> id;
            cout << "Name: "; cin >> newSurname;
            s->modifySurname(id, newSurname);
            s->displayEmployee(id);
        }
        case 3:{
            break;
        }
        case 4:{
            break;
        }
        case 5:{
            break;
        }
        case 6:{
            s->listAllEmployees();
            break;
        }
        case 0:
            cout << "La revedere!\n";
            break;
        default:
            cout << "Optiune invalida!\n";
        }
    }
    
    return 0;
}