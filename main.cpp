#include <iostream>
#include <ctime>
#include "Service.h"
using namespace std;

void displayEmployeeSettingsMenu(){
    cout <<" 1. Add employee;\n";
    cout <<" 2. Modify surname of employee;\n";
    cout <<" 3. Delete employee;\n";
    cout <<" 4. Search employee by CNP and display data;\n";
    cout <<" 5. Calculate salary;\n";
    cout <<" 6. Display list of employees;\n";
    cout <<" 0. Exit\n";
}
void displayMenu(){
    cout << "[SETTINGS] \n" ; 
    cout << "0. Exit\n";
    cout << "1. Employees\n";
    cout << "2. Appliances\n";
    cout << "3. Requests\n";
    cout << "4. Raports\n";
}


int main(){

    Service *s = Service::getInstance();

    cout << "Let's create our service! Loading database...";
    s->loadEmployeesFromFile("./tests/employee_init.csv");

    
    int option = -1;
    cout << "\n Hello boss! " << "What would you like to do today ? (choose your weapon 0 - 4)\n";
    while(option){
        displayMenu();
        cout <<"--------> Your option: "; cin >> option;
        switch (option)
        {
        case 0:{
            cout << "Bye bye Sunshine! \n";
            break;
        }
        case 1:{ //employees
            int option1 = -1;
            while(option1){
                displayEmployeeSettingsMenu();
                cout <<"--------> Your option: "; cin >> option1;
                    switch (option1)
                    {
                    case 1:{ //hire someone
                        string type, name, surname, city, cnp, hireDate;
                        cout << "Role (Supervisor, Technician, Receptionist): "; cin >> type;
                        cout << "Name: "; cin >> name;
                        cout << "Surname: "; cin >> surname;
                        cout << "City of Residence: "; cin >> city;
                        cout << "CNP: "; cin >> cnp;
                        cout << "Hire date(DD.MM.YYYY): " ; cin >> hireDate;
                        s->hireEmployee(name, surname, cnp, hireDate, city, type);
                        break;
                    }
                    case 2:{  //modify surname
                        string newSurname, surname, cnp;
                        cout << "Enter OLD SURNAME: ";  cin >> surname;
                        cout << "NEW SURNAME: "; cin >> newSurname;
                        cnp = s->modifySurname(surname, newSurname);
                        s->displayEmployee(cnp);
                    }
                    case 3:{ //fire someone 

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
                        cout << "Invalid Option!\n";
                    }
            }
            break;
        }
        case 2:{  //aplliances
            break;
        }
        case 3:{  //requests
            break;
        }
        case 4:{   //raports
            break;
        }

        default:
            break;
        }
    }
    
    return 0;
}