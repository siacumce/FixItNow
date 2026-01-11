#pragma once
#include <memory>
#include <ctime>
#include <string>
#include "Appliance.h"


class Request{
    private:
        static int nextID;
        int ID;

        shared_ptr<Appliance> device; 
        string timestamp; // data + hour - unique - there aren't any 2 requests with the same timestamp
        int complexity; // 1-5 and 0 - hopeless

        double estimatedDuration; // in unitati de timp (secunde pt simulare)  durata = vechime * complexitate
        double estimatedPrice; // pret_catalog*durata
        string generateTimestamp();
    public:
        Request(shared_ptr<Appliance> , int );

        int getID() const;
        int getComplexity() const;
        shared_ptr<Appliance> getDevice() const;
        double getPrice() const;
        double getDuration() const;
        string getTimestamp() const;

        void disp() const;
        ~Request() = default;
};