#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

inline bool isOldEnough(const string& CNP, const string& hireDate){
    int s = CNP[0] - '0';
    int yy = stoi(CNP.substr(1, 2)); // year >> 05 for 2005
    int mm = stoi(CNP.substr(3, 2)); // month
    int dd = stoi(CNP.substr(5, 2)); // day

    int birthYear = 0;

    if(s == 3 || s == 4){
        return true;
    }
    else if( s == 1 || s == 2){
        birthYear = 1900 + yy;
    }
    else if ( s == 5 || s == 6){
        birthYear = 2000 + yy;
    }
    else {
        birthYear = 2000 + yy;
    }

    int hireDay = stoi(hireDate.substr(0, 2));
    int hireMonth = stoi(hireDate.substr(3, 2));
    int hireYear = stoi(hireDate.substr(6, 4));

    int ageAtHiring = hireYear - birthYear;

    if(hireMonth < mm || (hireMonth == mm && hireDay < dd)){
        ageAtHiring --; // still his birthday has not passed
    }

    return ageAtHiring >= 16;
}

inline int getCurrentYear() {
    time_t t = time(nullptr);
    tm now;
    localtime_r(&t, &now);
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

inline bool validateCNP(string & cnp){

    cnp.erase(remove_if(cnp.begin(), cnp.end(),
    [](unsigned char c) { return !isdigit(c); }), cnp.end());

    if (cnp.length() != 13) {
        return false;
    }

    const int constant_C[] = {2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9};
    int sum = 0;

    for(int i = 0; i < 12 ; i++){
        int digit = cnp[i] - '0';
        // I make each letter a digit I multiply 
        // it by its correspondent in the constant_C
        // and sum it up
        sum += digit * constant_C[i];
    }

    int rest = sum % 11;
    int control_digit = (rest == 10)? 1 : rest; 

    int lastDigitOfCNP = cnp[12] - '0';

    if(control_digit != lastDigitOfCNP) {
        return false;
    }

    return true;
} 
