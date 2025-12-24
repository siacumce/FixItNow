#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

inline int getCurrentYear() {
    time_t t = time(nullptr);
    tm now;
    localtime_s(&now , &t);
    return now.tm_year + 1900;
}

inline int getYearFromString(const string &hireDate){
    if(hireDate.length() < 4) return getCurrentYear();

    try{
        return stoi(hireDate.substr(hireDate.length() - 4));
    }catch(const exception& e){
        cout << "It's something wrong about the date!";
        return getCurrentYear();
    }

}

inline int calculateYearsSince(const string &hireDate){
    int current = getCurrentYear();
    int hire_date = getYearFromString(hireDate);

    int no_of_years = current - hire_date;
    return (no_of_years < 0)? 0:no_of_years;
}

inline bool validateCNP(const string & cnp){
    if (cnp.length() != 13) return false;

    for(char c : cnp){
        if(!isdigit(c)) return false;
    }

    //ceva mai complicat
    return true;
} 