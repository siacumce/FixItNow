#include "Employee.h"
#include "Appliance.h"
#include "ApplianceFactory.h"
#include "EmployeeFactory.h"
#include "Request.h"
#include <map>

class Service{
    private: 
        static Service* instance;
        vector <shared_ptr<Employee>> employees;
        vector<shared_ptr<Appliance>> supportedAppliances; // load in loadSupportedAppliances()
        vector<shared_ptr<Appliance>> repairedAppliances; // for appliances menu 
        map <string, int> refusedAppliances; //for appliances menu
        vector<Request> waitingList; 
        Service() = default;

    public:
        Service(const Service &) = delete;
        Service& operator=(const Service&) = delete;
        //static factory method
        static Service* getInstance();
        bool isServiceFunctional() const;

        //Main Functionalities for employees
        void loadEmployeesFromFile(const string& );
        void hireEmployee(const string& , const string& , const string& , const string& ,const string& , const string& ); 
        void fireEmployee(int );
        void displayEmployeeSalary(string& );
        string modifySurname(const string&, const string&, string& );
        void listAllEmployees() const;
        void displayEmployee(string& ); 

        //Main Functionalities for Appliances
        void loadSupportedAppliances(const string& );
        void addAppliance(const string&, const string&, const string&, int, double, double);
        void removeSupportedAppliance(const string&, const string& );


        void listAllAppliances() const; // catalog
        void listRepairedAppliances() const;

        void displayRefusedOnes() const;
        void logRefusedOnes(const string& , const string& , const string& );

        //Repair Simulation
        void registerRequest(const string&, const string&, const string&, int, double, double, int );
        void loadRequestsFromFile(const string& ); //file
        void loadRequestsFromWaitingList() const;
        void runSimulation(const string&, double ); //file, duration and waiting list
        void displayWaitingList() const;
        ~Service();
};