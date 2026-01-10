#include "TV.h"

TV::TV(const string& brand,const string& model, int year, double price, int diagonal)
    :Appliance(brand, model, year, price), diagonal(diagonal){}

int TV::getDiag() const{
    return diagonal;
}
string TV::getType() const{
    return "TV";
}
void TV::disp() const {
    cout << "---------------------\n";
    cout << "Type: " << getType() << endl;
    Appliance::disp();
    cout << "Screen size: " << getDiag() << " cm" << endl;    
    cout << "---------------------\n";
}