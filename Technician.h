#include "Employee.h"


struct Competence {
    string type; // ex: "Frigider"
    string brand;     // ex: "Samsung"
};

class Technician: public Employee{
    private: vector <Competence> competences;
    vector <int> repairsValue;

    public:
        using Employee::Employee;
        Technician() = default;
        double calculateSalary() const override;
        double getTransportBonus() const override;

        double getTotalRepairsValue() const;
        void addSkill(const string& , const string& );
        bool canRepair(const string& , const string& );
        ~Technician() = default;
};