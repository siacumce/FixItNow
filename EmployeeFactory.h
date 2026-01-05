#pragma once
#include <iostream>
#include <memory>     
#include <string>
#include "Technician.h"
#include "Receptionist.h"
#include "Supervisor.h"
using namespace std;

class EmployeeFactory {
public:

    //static method --- used for being called w/o an object
    static shared_ptr<Employee> createEmployee(const string& type, const string& name, 
        const string& surname, const string& cnp, const string& hireDate, const string& city) {

        if (type == "Tehnician") {
            // std::make_shared is a Modern C++ module of making "new Technician(...)"
            return make_shared<Technician>(name, surname, cnp, hireDate, city);
        }
        else if (type == "Receptionist") {
            return make_shared<Receptionist>(name, surname, cnp, hireDate, city);
        }
        else if (type == "Supervisor") {
            return make_shared<Supervisor>(name, surname, cnp, hireDate, city);
        }
        else {
            throw invalid_argument("Tip angajat necunoscut: " + type);
        }
    }
};