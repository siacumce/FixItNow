#pragma once
#include <iostream>
#include <memory>     
#include <string>
#include "TV.h"
#include "Fridge.h"
#include "WM.h"
using namespace std;

class ApplianceFactory{
    public: 
        static shared_ptr <Appliance> createAppliance(
        const string& type, 
        const string& brand, 
        const string& model, 
        int year, 
        double price, 
        int extraAttribute // it could be the display size, the capacity or 1/0 for freezer
    ) {
        if(type == "Fridge"){
            bool freezer = (extraAttribute > 0);
            return make_shared<Fridge>(brand, model, year, price, freezer);
        }
        else if(type == "TV"){
            return make_shared<TV>(brand, model, year, price, extraAttribute);
        }
        else if(type == "Washing-Machine" || type == "WM"){
            return make_shared<WM>(brand, model, year, price, extraAttribute);
        }
        else {
            throw invalid_argument("Unknown appliance type: " + type);
        }
    }
};