#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
    protected:
        const int BASE_SALARY = 4000; 
        string name;
        string surname;
        string CNP; 
        string hireDate;
        string residenceCity;
        const int employeeID;
        static int nextID;

    public:
    Employee(string , string , string , string , string );
    
    //The salary part
    virtual double calculateSalary() const = 0;
    //base + transport + seniority
    double calculateBaseEarnings() const;

    //getters for basic bonus
    virtual double getTransportBonus() const;
    virtual double getSeniorityBonus() const;

    // Getters/Setters for display
    void setSurname(const string& );    
    int getId() const;
    string getCNP() const;
    string getSurname() const;
    string getName() const;
    virtual string getRole() const = 0;
    
    virtual void disp() const;

    virtual ~Employee() = default; 
};  