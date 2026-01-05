#include "Employee.h"

class Supervisor : public Employee {
    public:
        using Employee::Employee; 
        Supervisor() = default;
        double calculateSalary() const override;
        string getRole() const override;
        void disp() const override;
        ~Supervisor() = default;
};

