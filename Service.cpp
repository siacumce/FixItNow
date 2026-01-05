#include "Service.h"
#include "EmployeeFactory.h"
#include <fstream>
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
        cout << "[SUCCES] Employee added: " << name << " " << surname << endl;
    }
    catch(const exception& e){
        cout << "[ERROR] Employee not added !!! " << name << ": " << e.what() << endl;
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

        

    }
}