#include "Employee.h"

class Receptionist: public Employee{
    protected: 
        vector <int> requestID;
    public:
    using Employee::Employee;
    void addID(const string&);
    double calculateSalary() const override;
    void disp() const override;
    string getRole() const override;

    void addRequestID(int );
    ~Receptionist() = default;
};