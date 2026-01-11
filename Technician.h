#include "Employee.h"
#include "Request.h"
#include <deque>

struct Competence {
    string type; // ex: "Fridge"
    string brand;     // ex: "Samsung"
};

class Technician: public Employee{
    private: vector <Competence> competences;
    vector <int> repairsValue;
    int maxRepairDuration = 0;
    int timeLeft = 0;
    deque <shared_ptr<Request>> activeQRequests;

    public:
        using Employee::Employee;
        Technician() = default;
        double calculateSalary() const override;
        double getTransportBonus() const override;

        double getTotalRepairsValue() const;
        void addSkill(const string& , const string& );
        bool canRepair(const string& , const string& );
        void disp() const override;
        string getRole() const override;


        bool isAvailable() const;
        void assignReq(shared_ptr<Request> );
        shared_ptr<Request> executeWork();
        shared_ptr<Request> getCurrentWork() const;
        int getTimeLeft() const;
        int getQueueSize() const;
        int getMaxRepairDuration() const;
        ~Technician() = default;
};