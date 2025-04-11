#include "Date.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <array>
using namespace std;

//Mutator functions
void Date::set(int month_, int day_, int year_, int hour_){
    month = month_;
    day = day_;
    year = year_;
    hour = hour_;
}

//Overloaded operators
//Less than operator, true if date is less than rhs
bool Date::operator<(const Date & rhs){
    if(year != rhs.year) return year < rhs.year;
    if(month != rhs.month) return month < rhs.month;
    if(day != rhs.day) return day < rhs.day;
    return hour < rhs.hour;
}

//Overloaded equality operator
bool Date::operator==(const Date & rhs){
    return(month == rhs.month && day == rhs.day && year == rhs.year && hour == rhs.hour);
}

//Overloaded less than or equal to operator
bool Date::operator<=(const Date & rhs){
    //uses our overloaded less than and equality operators
    return (*this < rhs || *this == rhs);
}

//leap year function
int countLeapYears(int year, int month){
    //if february 29th hasn't passed, subtract 1
    if(month <= 2) year--;

    //leap year is divisible by 4, but not 100 unless also % 400
    return year / 4 - year / 100 + year / 400;
}

//Overloaded minus operator
int Date::operator-(const Date & rhs){
    //implement array to hold days since Jan 1st
    array<int, 12> daysSinceJan = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    //calculate elapsed time
    int elapsedTime = 0;
    elapsedTime += (year - rhs.year) * 365; //days in years
    elapsedTime += (daysSinceJan[month - 1] + day) - (daysSinceJan[rhs.month - 1] + rhs.day); //days in months

    elapsedTime *= 24; //convert to hours
    elapsedTime += hour - rhs.hour;

    //leap year check
    //leap year happens on Feb 29th (depending on the testing system, may have to go back and remove month check) (month > 2)
    int leapYearDifference = countLeapYears(year, month) - countLeapYears(rhs.year, rhs.month);
    elapsedTime += leapYearDifference*24;

    return elapsedTime;

    

}

//Print function
void Date::print(){
    //"Month dd, yyyy, hh:00"
    string monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    cout << monthNames[month-1] << " " << day << ", " << year << ", " << hour << ":00";
    //setfill can fill in 0s depending on setw
    //dont use setfill I guess
}