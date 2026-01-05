#include "Employee.h"
#include "EmployeeFactory.h"

class Service{
    private: 
        static Service* instance;
        vector <shared_ptr<Employee>> employees;
        Service() = default;

    public:
        Service(const Service &) = delete;
        Service& operator=(const Service&) = delete;

        //static factory method
        static Service* getInstance();

        //Main Functionalities for employees
        
        void loadEmployeesFromFile(const string& );

        void hireEmployee(const string& , const string& , 
                   const string& , const string& ,
                   const string& , const string& ); 
        
        void fireEmployee(int );
        
        void modifySurname(int , const string& );

        void listAllEmployees() const;
        
        ~Service();

};