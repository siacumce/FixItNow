#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Appliance{
    private:
        string brand;
        string model;
        int manufacturingYear;
        double price;
    public:
        Appliance(const string&,const string&, int, double);
        
        string getModel() const;
        string getBrand() const;
        int getYear() const;
        double getPrice() const;

        virtual string getType() const = 0;
        virtual void disp() const;
         
        virtual ~Appliance() =  default;
};