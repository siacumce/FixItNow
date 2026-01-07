#include "WH.h"

WM::WM(string& brand, string& model, int year, double price, int capacity)
    :Appliance(brand, model, year, price), capacity(capacity){}

int WM::getCapacity() const{
    return capacity;
}
string WM::getType() const{
    return "Washing-Machine";
}
void WM::disp() const {
    cout << "---------------------\n";
    cout << "Type: " << getType() << endl;
    Appliance::disp();
    cout << "Capacity: " << getCapacity() << endl;    
    cout << "---------------------\n";
}