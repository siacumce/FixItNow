#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
    protected:
        int BASE_SALARY = 4000; 
        string name;
        string surname;
        string CNP; 
        string hireDate;
        string residenceCity;
        const int employeeID;
        static int nextID;

    public:
    Employee(string , string , string , const int , string , string );
    
    //The salary part
    virtual double calculateSalary() const = 0;
    //bse+transport+seniority
    double calculateBaseEarnings() const;

    //getters for basic bonus
    virtual double getTransportBonus() const;
    virtual double getSeniorityBonus() const;

    // Getters for display
    //virtual string getFullName() const = 0;
    //virtual string getCNP() const = 0;
    int getId() const;
    void disp() const;
    virtual ~Employee() = default; 
};  