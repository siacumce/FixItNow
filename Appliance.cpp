#include "Appliance.h"

Appliance::Appliance(const string& brand,const string& model, int manYear, double price):brand(brand), 
    model(model), manufacturingYear(manYear), price(price){}

string Appliance::getModel() const{
    return Appliance::model;
}
string Appliance::getBrand() const{
    return Appliance::brand;
}
void Appliance::disp() const{
    cout << "Brand: " << getBrand() << endl;
    cout << "Model: " << getModel() << endl;
}
double Appliance::getPrice() const{
    return Appliance::price;
}
int Appliance::getYear() const{
    return Appliance::manufacturingYear;
}

