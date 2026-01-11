#include "Technician.h"

double Technician::getTotalRepairsValue() const{
    double totalRepairsValue = 0;
    for(const auto& x : repairsValue){
        totalRepairsValue += x;
    }
    return totalRepairsValue;
}
double Technician::getTransportBonus() const{
    return Employee::getTransportBonus();
}
double Technician::calculateSalary() const {
    double base_salary = Employee::calculateBaseEarnings();
    
    //bonus 
    double totalRepairsValue = getTotalRepairsValue();
    double repairBonus = 0.2*totalRepairsValue;
    return base_salary + repairBonus;
}
void Technician::addSkill(const string &type, const string &brand) {
    competences.push_back({type, brand});
}
bool Technician::canRepair(const string& type, const string& brand){
    for(const auto& comp : competences){
        if(comp.type == type && comp.brand == brand){
            return true;
        }
    }
    return false;
}
string Technician::getRole() const{
    return "Technician";
}
void Technician::disp() const{
    Employee::disp();
    cout << " Role: " << getRole() << endl;
    cout << " Current Month Salary: " << calculateSalary() << endl; 
    cout << "---------------------" << endl;
}
bool Technician::isAvailable() const{
    return activeQRequests.size() < 3;
}
void Technician::assignReq(shared_ptr<Request> R){
    activeQRequests.push_back(R);
    
    if(activeQRequests.size() == 1 ){
        timeLeft = (int)R->getDuration();
    }
}
shared_ptr<Request> Technician::executeWork(){
    if(activeQRequests.empty()) return nullptr;

    timeLeft --;
    if(timeLeft <= 0){
        auto finishedReq = activeQRequests.front();

        repairsValue.push_back((int)finishedReq->getPrice()); 
        
        activeQRequests.erase(activeQRequests.begin());
        if(!activeQRequests.empty()){
            timeLeft = (int)finishedReq->getDuration();
        }
        if (finishedReq->getDuration() > maxRepairDuration){
           maxRepairDuration = finishedReq->getDuration(); // for the report
        }
        return finishedReq;
    }
    return nullptr;

}
shared_ptr<Request> Technician::getCurrentWork() const {
        if (activeQRequests.empty()) return nullptr;
        return activeQRequests.front();
    }
int Technician::getQueueSize() const { return activeQRequests.size(); }
int Technician::getTimeLeft() const { return timeLeft; }
int Technician::getMaxRepairDuration() const { return maxRepairDuration; }