#include "Request.h"
using namespace std;

int Request::nextID = 0;
string Request::generateTimestamp() {
    time_t now = time(0);
    string dt = ctime(&now);    // Il convertim direct in text
    // ctime pune automat un 'Enter' (\n) la final. 
    if (!dt.empty()) {
        dt.pop_back(); 
    }
    return dt;

}
Request::Request(shared_ptr<Appliance> dev, int complexity):device(dev), complexity(complexity), ID(nextID++){
    this->timestamp = generateTimestamp(); //that s why the generateTimestamp is private;

    if(complexity < 1) complexity = 1;
    if(complexity > 5) complexity = 5;

    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    int currentYear = ltm->tm_year + 1900;
    int age = currentYear - device->getYear();
    if (age < 1) age = 1;

    this->estimatedDuration = age* this->complexity;
    this->estimatedPrice = this->estimatedDuration*device->getPrice();
}
void Request::disp() const{
    cout << "[ID REQUEST: " << ID << " ] " << "[ " << timestamp << " ]\n";
    cout << "Appliance: " << device->getModel() << " " << device->getBrand() << endl;
    cout << "Est. Duration: " << estimatedDuration << " sec | Est. Price: " << estimatedPrice << " RON\n";
}
int Request::getID() const{
    return ID;
}
int Request::getComplexity() const{
    return complexity;
}
shared_ptr<Appliance> Request::getDevice() const{
    return device;
}
double Request::getPrice() const{
    return estimatedPrice;
}
double Request::getDuration() const{
    return estimatedDuration;
}
string Request::getTimestamp() const{
    return timestamp;
}