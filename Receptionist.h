#include "Employee.h"

class Receptionist: public Employee{
    protected: 
        vector <string> requestID;
    public:
    using Employee::Employee;
    void addID(const string&);
    double calculateSalary() const override;
    void disp() const override;
    string getRole() const override;
    ~Receptionist() = default;
};