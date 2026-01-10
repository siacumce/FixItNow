#include "Fridge.h"

Fridge::Fridge(const string& brand, const string& model, int year, double price, bool hasFreezer)
    :Appliance(brand, model, year, price), hasFreezer(hasFreezer){}

string Fridge::getType() const{
    return "Fridge";
}

void Fridge::disp() const {
    cout << "---------------------\n";
    cout << "Type: " << getType() << endl;
    Appliance::disp();
    cout << "Freezer: ";
    if(hasITFreezer())
        cout << "YES " << endl;
    else cout << "NO " << endl;
    cout << "---------------------\n";
}
bool Fridge::hasITFreezer() const{
    return hasFreezer;
}