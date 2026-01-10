#include "Service.h"
#include "EmployeeFactory.h"
#include <fstream>
#include <sstream>
#include <algorithm> 

// initialization of static member 
Service* Service::instance = nullptr;

void notFound(bool found, const string& cnp){
    if(found == 0)
        cout << "Employee with the CNP " << cnp << " was not found." << endl;
}
Service* Service::getInstance() {
    if (instance == nullptr) {
        instance = new Service();
    }
    return instance;
}

void Service::hireEmployee(const string& name, const string& surname, 
                   const string& cnp, const string& hiredate,
                   const string& city, const string& type){

    try{
        auto newEmp = EmployeeFactory::createEmployee(type, name, surname, cnp, hiredate, city);
        employees.push_back(newEmp);
        cout << "[SUCCESS] Employee added: " << name << " " << surname << endl << "---------------------" << endl;
    }
    catch(const exception& e){
        cout << "[ERROR] Employee " << name << " " << surname << " was not added! " << e.what() << endl << "---------------------" << endl;
    }
}

string trim(const string& str){
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}
void Service::loadEmployeesFromFile(const string& filePath){
    ifstream f(filePath);

    if(!f.is_open()){
        cout << "Error: the file could not be opened! " << filePath << endl;
        return;
    }

    string line;
    int count_lines = 0;

    while(getline(f, line)){
        count_lines ++;
        if (line.empty() || line[0] == '#') continue;

        string data;
        vector <string> rowData;
        stringstream ss(line);
        while(getline(ss, data, ',')){
            rowData.push_back(trim(data));
        }
        
        try{
            string type = rowData[0];
            string name = rowData[1];
            string surname = rowData[2];
            string cnp = rowData[3];
            string date = rowData[4];
            string city = rowData[5];

            auto emp = EmployeeFactory::createEmployee(type, name, surname, cnp, date, city);
            auto tech = dynamic_pointer_cast <Technician> (emp);
            //if this cast would not return a null pointer, the returned object shares ownership
            // over what the pointer indicates to
            if(tech != nullptr ){
                for(int i = 6; i < rowData.size(); i+= 2){ // + 2  because the data read is paired in 2 > type + brand
                    tech -> addSkill(rowData[i], rowData[i+1]);
                }
            }
            employees.push_back(emp);
        }catch(const exception& e){
            cout << "[EROARE Linia " << count_lines << "] " << e.what() << endl;
        }        
    }

     f.close();
     cout << "\n---Employee upload completed---" << endl;
}
string Service::modifySurname(const string& cnp, const string& oldSurname, string& newSurname){
    bool found = false;

    for(auto& emp : employees){
        if(emp->getCNP() == cnp){
            found = true;
            emp->setSurname(newSurname);
            return emp->getCNP();
        }
    }
    notFound(found, cnp);
    return "";
}
void Service::listAllEmployees() const {
    for (const auto& emp : employees) {
        // polimorfism -- disp() specifică tipului ***real*** al obiectului
        emp->disp(); 
    }

    cout << "---------------------" << endl;
}
void Service::displayEmployee(string& CNP) {
    bool found = false;
    for (const auto& emp : employees) {
        if (emp->getCNP() == CNP) { 
            found = true;
            cout << "---------------------------------" << endl;
            emp->disp(); 

            cout << "[Rol detected: ";
        
            if (dynamic_cast<Supervisor*>(emp.get()) != nullptr) {
                cout << "SUPERVISOR ]";
                // Opțional: Poți accesa și metode specifice Supervizorului
                // auto sup = dynamic_cast<Supervisor*>(emp.get());
                // cout << " (Echipa: " << sup->getEchipa() << ")";
            }
            else if (dynamic_cast<Technician*>(emp.get()) != nullptr) {
                cout << "TECHNICIAN ]";
            }
            else if (dynamic_cast<Receptionist*>(emp.get()) != nullptr) {
                cout << "RECEPTIONIST ]";
            }
            else {
                cout << "UNKNOWN ]";
            }
            cout << endl << "---------------------------------" << endl;
            break; 
        }
    }
    notFound(found, CNP);
}
void Service::fireEmployee(int ID) {
    bool found = false;

    for (auto emp = employees.begin(); emp != employees.end(); ++emp){
        if((*emp)->getId() == ID){
            found = true;
            employees.erase(emp); 
            cout << "Employee with ID " << ID <<" was deleted successfully. \n";
            break;
        }
    }

    if (!found) {
        cout << "Employee with the ID " << ID << " was not found." << endl;
    }
}

//Appliances Factory
void Service::loadSupportedAppliances(const string &filePath){
    ifstream f(filePath);

    if(!f.is_open()){
        cout << "Error: the file could not be opened! " << filePath << endl;
        return;
    }

    int count = 0;
    string line;
    while(getline(f, line)){
        count ++;
        if (line.empty() || line[0] == '#') continue;
        string data;
        vector<string> rowData;
        stringstream ss(line);
        while(getline(ss, data, ',')){
            rowData.push_back(trim(data));
        }
        try{
            string type = rowData[0];
            string brand = rowData[1];
            string model = rowData[2];
            int year = stoi(rowData[3]);
            double price = stod(rowData[4]);
            double extra = stod(rowData[5]);
            auto app = ApplianceFactory::createAppliance(type, brand, model, year, price, extra);
            if (app != nullptr) {
                supportedAppliances.push_back(app);
            }
        }catch(const exception& e){
            cout << "[EROARE Linia " << count << "] " << e.what() << endl;
        }
    }
    f.close();
    cout << "Appliances Data Base uploaded.\n";
}
bool Service::isServiceFunctional() const {
    int techCount = 0;
    int recepCount = 0;
    int superCount = 0;  
    
    for(const auto& emp : employees){

        if(dynamic_pointer_cast<Technician>(emp))
            techCount++;
        else if(dynamic_pointer_cast<Supervisor>(emp))
            superCount++;
        else if(dynamic_pointer_cast<Receptionist>(emp))
            recepCount++;
        //or I can use getRole()
    }

    bool verify = 1;
    if(techCount < 3) verify = 0;
    if(recepCount < 1) verify = 0;
    if(superCount < 1) verify = 0;

    if(!verify){
        cout << "\n[!] ATENTION: the service could not function!" << endl;
        cout << "   Conditions: Min. 3 Technicians, 1 Receptionist, 1 Supervisor." << endl;
        cout << "   Current:  " << superCount << " Supervisors, " << techCount << " Tehnicians, " << recepCount << " Receptionists. " << endl;
        return false;
    }
    return true;
}
void Service::listAllAppliances() const{
    for (const auto& app : supportedAppliances) {
        app->disp(); 
    }
    cout << "---------------------" << endl;
}
void Service::addAppliance(const string& type, const string& brand, const string& model, int year, double price, double extra){
    try{
        auto app = ApplianceFactory::createAppliance(type, brand, model, year, price, extra);
        supportedAppliances.push_back(app);
        cout << "[SUCCESS] The device " << brand << " " << model << " was added in the catalog.\n";
    }catch(const exception& e){
        cout << "[ERROR] The device could not be added: " << e.what() << endl;
    }
}
void Service::removeSupportedAppliance(const string& brand, const string& model){
    bool found = false;
    for(auto app = supportedAppliances.begin(); app != supportedAppliances.end(); app++){
        if((*app)->getBrand() == brand && (*app)->getModel() == model){
            supportedAppliances.erase(app);
            found = true;
            cout << "[SUCCESS] The model " << brand << " " << model << " was deleted from the catalog.\n";
            break;
        }
    }
    if(!found)
        cout << "[INFO] The model " << brand << " " << model << " does not exist in the catalog.\n";
}

//Simulation and repair
void Service::listRepairedAppliances() const{
    if(!repairedAppliances.size()){
        cout << "There aren't any repaired devices! \n";
        return;
    }
    cout << "------HISTORY------" << endl;
    for (const auto& app : repairedAppliances) {
        app->disp(); 
        cout << "-------------------------\n";
    }
}
void Service::registerRequest(const string& type, const string& brand, const string& model, int year, double price, double extra, int complexity){
    shared_ptr<Receptionist> rec = nullptr;
    
    for (auto& emp : employees) {
        rec = dynamic_pointer_cast<Receptionist>(emp);
        if (rec != nullptr) {
            break; 
        }
    }
    if (rec == nullptr) {
        cout << "[EROARE] We do not have any receptionist! We cannot have requests!\n";
        return; 
    }
    
    bool isSupported = false;
    for(const auto& app : supportedAppliances){
        if(app->getType() == type && app->getModel() == model && app->getBrand() == brand){
            isSupported = true;
            break;
        }
    }

    if(!isSupported){
        cout << "[REFUSED] Model " << brand << " " << model << " is not supported\n";
        logRefusedOnes(type, brand, model);
        return;
    }
    try{
        auto app = ApplianceFactory::createAppliance(type, brand, model, year, price, extra);
        Request req(app, complexity);
        waitingList.push_back(req);

        //add ID in requestID vector from receptionist
        rec->addRequestID(req.getID());

        cout << "Request has been registered by the receptionist: " << rec->getName() << " " << rec->getSurname() << endl;
    }catch(const exception&e){
        cout << "[ERROR] Invalid Data on creating request: " << e.what() << endl;
    }

}
// void Service::runSimulation(const string& filePath, int time){
//      ;
// }
void Service::displayWaitingList() const{
    cout << "======= WAITING LIST ======= \n";
    if(waitingList.empty()){
        cout << "There aren't any requests in waiting.\n";
    }
    else{
        for(const auto& req : waitingList){
            req.disp();
        }
    }
    cout << "---------------------" << endl;
}

//static means i make this function private tot this file, instead of global in the entire set of files
static bool cmp(pair<string, int>& a, pair<string, int>& b) 
{ 
    return a.second > b.second; 
}

void Service::displayRefusedOnes() const{
    if(refusedAppliances.empty()){
        cout << "There are not any refused appliances.\n";
        return;
    }
    //I have to sort the occurrence count
    vector<pair<string, int>> A;

    for (auto& map_val : refusedAppliances){
        A.push_back(map_val);
    }
    sort(A.begin(), A.end(), cmp);
    cout << "======= REFUSAL STATISTICS =======\n";
    for (auto& keys : A) { 
        cout << keys.first << ' '<< keys.second << endl; 
    } 

}
void Service::logRefusedOnes(const string& type, const string& brand, const string& model){
    string value = type + " | " + brand + " " + model;
    //increment its key
    refusedAppliances[value]++;
}
void Service::loadRequestsFromWaitingList() const{;}
void Service::loadRequestsFromFile(const string& filePath){;
    ifstream f("filePath");

    if(!f.is_open()){
        cout << "The file: " << filePath << " could not be opened.\n";
        return;
    }

    int count = 0;
    string line;
    while(getline(f,line)){
        count ++;
        string data;
        vector<string> dataRow;
        stringstream segment(line);

        while(getline(segment, data, ',')){
            dataRow.push_back(trim(data));
        }

        try{
            string type = dataRow[0];
            string brand = dataRow[1];
            string model = dataRow[2];
            int year = stoi(dataRow[3]);
            double price = stoi(dataRow[4]);
            double extra = stoi(dataRow[5]);
            int complexity = stoi(dataRow[6]);

            registerRequest(type, brand, model, year, price, extra, complexity);
            ///AICICICICICIICIC AI RAMAS

        }catch (const exception& e) {
            cout << "[ERROR] LINE " << count  << " " << e.what() << endl;
        }

        f.close();
    }

}
