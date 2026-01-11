#include <iostream>
#include <ctime>
#include "Service.h"
using namespace std;

void EmployeeSettingsMenu(){
    cout <<" 0. Exit\n";
    cout <<" 1. Add employee;\n";
    cout <<" 2. Modify surname of employee;\n";
    cout <<" 3. Delete employee;\n";
    cout <<" 4. Search employee by CNP and display data;\n";
    cout <<" 5. Display List of Employees;\n";
}
void RequestMenu(){
    cout << "0. Exit\n";
    cout << "1. Add Request\n";
    cout << "2. Run Requests\n";
}
void AppliancesSettingsMenu(){
    cout <<" 0. Exit\n";
    cout <<" 1. Display Appliance Catalog.\n";
    cout <<" 2. Add/delete brand & model\n";
    cout <<" 3. Display repair history\n";
    cout <<" 4. Display refusal list\n";
}
void ReportMenu(){
    cout << "0. Exit\n";
    cout << "1. Top 3 Salaries\n";
    cout << "2. Longest Repair\n";
    cout << "3. Waiting List\n";
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

    cout << "Let's create our service! Loading database...\n";
    //s->loadEmployeesFromFile("./tests/employee_init.csv");
    //s->loadEmployeesFromFile("./tests/employee_init_errors.csv");
    //s->loadEmployeesFromFile("./tests/debug_employees.csv");

    
    int option = -1;
    cout << "\n Hello boss! " << "What would you like to do today ? (choose your weapon 0 - 4)\n";
    while(option){
        displayMenu();
        cout <<"--------> Your option: "; cin >> option;
        switch (option){
        case 0:{
            cout << "Bye bye Sunshine! \n";
            break;
        }
        case 1:{ //employees
            int option1 = -1;
            s->loadEmployeesFromFile("./tests/employee_init.csv");
            while(option1){
                EmployeeSettingsMenu();
                cout <<"--------> Your option: "; cin >> option1;
                    switch (option1){
                    case 1:{ //hire someone
                        cin.ignore(); 
                        string type, name, surname, city, cnp, hireDate;
                        cout << "Role (Supervisor, Technician, Receptionist): "; getline(cin, type);
                        cout << "Name: "; getline(cin, name);
                        cout << "Surname: "; getline(cin, surname);
                        cout << "City of Residence: "; getline(cin, city);
                        cout << "CNP: "; getline(cin, cnp);
                        cout << "Hire date(DD.MM.YYYY): " ; getline(cin, hireDate);
                        s->hireEmployee(name, surname, cnp, hireDate, city, type);
                        break;
                    }
                    case 2:{  //modify surname
                        cin.ignore(); 
                        string newSurname, surname, cnp;
                        cout << "Enter CNP: "; getline(cin, cnp);
                        cout << "Enter OLD SURNAME: ";  getline(cin, surname);
                        cout << "NEW SURNAME: "; getline(cin, newSurname);
                        cnp = s->modifySurname(cnp, surname, newSurname);

                        if(cnp != "") {
                            cout << " Modified ! " << endl;
                            s->displayEmployee(cnp);
                            break;
                        }
                        break;
                    }
                    case 3:{ //fire someone 
                        cin.ignore(); 
                        int id;
                        cout << "Enter ID: " ; cin >> id;
                        s->fireEmployee(id);
                        break;
                    }
                    case 4:{
                        cin.ignore();
                        string cnp;
                        cout << " Enter CNP: "; getline(cin, cnp);
                        s->displayEmployee(cnp);
                        break;
                    }
                    case 5:{
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
            if (s->isServiceFunctional() == false) {
                cout << "Please hire people, the service is not functional yet. \n";
                break; 
            }
            int option2 = - 1;
            s->loadSupportedAppliances("./tests/supported_appliances.csv");
            //s->loadSupportedAppliances("./tests/debug_catalog.csv");
            while(option2){
                AppliancesSettingsMenu();
                cout <<"--------> Your option: "; cin >> option2;
                switch (option2)
                {
                case 0:{
                    cout << "Have a nice day !\n";
                    break;
                }
                case 1:{ // catalog
                    s->listAllAppliances();
                    break;
                }
                case 2:{
                    cin.ignore();
                    int choose = -1;
                    while(choose){
                        cout << "Add - [press 1]\tDelete - [press 2]\tExit - [press anything]:  "; cin  >> choose;
                        string brand, model, type;
                        int year;
                        double price, extra;
                        cin.ignore();
                        if(choose == 1){
                            cout << "[ENTER] What device would you like to ADD?\n Type (Fridge, TV, Washing-Maachine): "; getline(cin, type);
                            cout << "Brand: "; getline(cin, brand);
                            cout << "Model: "; getline(cin, model);
                            cout << "Price: "; cin >> price;
                            cout << "Fabrication year: "; cin >> year;
                            cout << "Display size || Capacity || Has_Or_Has_Not_Freezer: "; cin >> extra;
                            s->addAppliance(type, brand, model, year, price, extra);
                        }
                        else if(choose == 2){
                            cout << "[ENTER] What device would you like to DELETE? Brand: "; getline(cin,brand);
                            cout << "Model: "; getline(cin, model);
                            s->removeSupportedAppliance(brand, model);
                        }
                        else break;
                    }
                    break;
                }
                case 3:{ // history of repaired
                    s->listRepairedAppliances();
                    break;
                }
                case 4:{
                    //refused ones statistics 
                    s->displayRefusedOnes();
                    break;
                }
                default:
                    break; 
                }
            }
            break;
        }
        case 3:{  //requests
            if (s->isServiceFunctional() == false) {
                cout << "Please hire people, the service is not functional yet. \n";
                break; 
            }
            int option3 = -1;
            while(option3){
                //Request menu
                RequestMenu();
                cout << "-------->Your option: "; cin >> option3;
                switch (option3)
                {
                case 1:{ // enter request by hand -- the manual part
                    cin.ignore();
                    string type, brand, model;
                    int year, complexity;
                    double price, extra;
                    cout << "Tip (TV/Fridge/Washing-Machine): "; getline(cin, type);
                    cout << "Brand: "; getline(cin, brand);
                    cout << "Model: "; getline(cin, model);
                    cout << "Price: "; cin >> price;
                    cout << "Fabrication year: "; cin >> year;
                    cout << "Display size || Capacity || Freezer--[0/1]: "; cin >> extra;
                    cout << "Complexitate (1-5): "; cin >> complexity;
                    s->registerRequest(type, brand, model, year, price, complexity, extra); //this goes into the wainting list
                    break;
                }
                case 2:{ // simulate reading request from database/file  + repair simulatation real-time --> the automated part
                    cin.ignore();
                    string filename;
                    int time;
                    cout << "[ENTER] filename (e.g , ./tests/requests.csv ): "; getline(cin, filename);
                    cout << "Simulation Duration (seconds): "; cin >> time;
                    s->loadRequestsFromFile(filename);
                    s->runSimulation(time); // all go into the waiting list and then they are shared to the technicians => + history of repaired ones
                    break;
                } 
                case 3:{ // list wating list
                    s->displayWaitingList();
                    break;
                } 
                case 0:{
                    cout <<"GoodBye! \n";
                    break;
                }              
                default:
                    break;
                }
            }
            break;
        }
        case 4:{   //raports
            if (s->isServiceFunctional() == false) {
                cout << "Please hire people, the service is not functional yet. \n";
                break; 
            }
            int option4 = -1;
            while (option4)
            {
                cout << "Loading Reports\n";
                //Report Menu
                ReportMenu();
                cout << "-------->Your option: "; cin >> option4;
                switch (option4)
                {
                case 1:{
                    s->generateTopSalariesReport("report_top_salaries.csv");
                    break;
                }
                case 2:{
                    s->generateLongestRepairReport("report_longest_repair.csv");
                    break;
                }
                case 3:{
                    s->generateWaitingListReport("report_waiting_list.csv");
                    break;
                }
                default:
                    break;
                }
            }
            
            break;
        }
        default:
            break;
        }
    }
    return 0;
}