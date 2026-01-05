#include "Service.h"
#include "EmployeeFactory.h"
#include <fstream>
#include <sstream>
#include <algorithm> 

// initialization of static member 
Service* Service::instance = nullptr;

Service* Service::getInstance() {
    if (instance == nullptr) {
        instance = new Service();
    }
    return instance;
}

void Service::hireEmployee(const string& name, const string& surname, 
                   const string& cnp, const string& hiredate,
                   const string& city, const string& type){

    try{
        auto newEmp = EmployeeFactory::createEmployee(type, name, surname, cnp, hiredate, city);
        employees.push_back(newEmp);
        cout << "[SUCCESS] Employee added: " << name << " " << surname << endl;
    }
    catch(const exception& e){
        cout << "[ERROR] Employee " << name << " " << surname << " was not added! " << e.what() << endl;
    }
}

void Service::loadEmployeesFromFile(const string& filePath){
    ifstream f(filePath);

    if(!f.is_open()){
        cout << "Error: the file could not be opened! " << filePath << endl;
        return;
    }

    string line;
    int count_lines = 0;

    while(getline(f, line)){
        count_lines ++;
        if (line.empty() || line[0] == '#') continue;

        string data;
        vector <string> rowData;
        stringstream ss(line);

        while(getline(ss, data, ',')){
            rowData.push_back(data);
        }
        
        try{
            string type = rowData[0];
            string name = rowData[1];
            string surname = rowData[2];
            string cnp = rowData[3];
            string date = rowData[4];
            string city = rowData[5];

            auto emp = EmployeeFactory::createEmployee(type, name, surname, cnp, date, city);
            auto tech = dynamic_pointer_cast <Technician> (emp);
            //if this cast would not return a null pointer, the returned object shares ownership over what the pointer indicates to
            if(tech != nullptr ){
                for(int i = 6; i < rowData.size(); i+= 2){ // + 2  because the data read is paired in 2 > type + brand
                    tech -> addSkill(rowData[i], rowData[i+1]);
                }
            }

            employees.push_back(emp);

        }catch(const exception& e){
            cout << "[EROARE Linia " << count_lines << "] " << e.what() << endl;
        }        
    }

     f.close();
     cout << "\n---Employee upload completed---" << endl;
}

void Service::modifySurname(int id, const string& surname){
    bool found = false;

    for(auto& emp : employees){
        if(emp->getId() == id){
            found = true;
            emp->setSurname(surname);
            break;
        }
    }

    if(!found){
        cout << "Employee with the ID " << id << " was not found." << endl; 
    }
}

void Service::listAllEmployees() const {
    for (const auto& emp : employees) {
        // polimorfism
        // disp() specifică tipului ***real*** al obiectului
        emp->disp(); 
    }
}


void Service::displayEmployee(int id) {
    bool found = false;

    for (const auto& emp : employees) {
        if (emp->getId() == id) { 
            found = true;
            cout << "---------------------------------" << endl;
            emp->disp(); 

            cout << "Rol detectat: ";
        
            if (dynamic_cast<Supervisor*>(emp.get()) != nullptr) {
                cout << "SUPERVISOR";
                // Opțional: Poți accesa și metode specifice Supervizorului
                // auto sup = dynamic_cast<Supervisor*>(emp.get());
                // cout << " (Echipa: " << sup->getEchipa() << ")";
            }

            else if (dynamic_cast<Technician*>(emp.get()) != nullptr) {
                cout << "TECHNICIAN";
            }
            else if (dynamic_cast<Receptionist*>(emp.get()) != nullptr) {
                cout << "RECEPTIONIST";
            }
            else {
                cout << "UNKNOWN ROLE";
            }
            cout << endl << "---------------------------------" << endl;
            break; 
        }
    }
    if (!found) {
        cout << "Employee with the ID " << id << " was not found." << endl;
    }
}