
#include "date.h"
#include <iostream>
using namespace std;
//implementation of date class

Date::Date(){
    month =0;
    year =0;
    day =0;
}
Date::Date(int d, int m, int y){
    day = d;
    month = m;
    year = y;
} 
void Date::setDay(int d){
    if (d<1||d>31)
        throw WrongInput();
    else
        day = d;
}
void Date::setMonth(int m){
    if (m<1||m>12)
        throw WrongInput();
    else 
        month=m;
}
void Date::setYear(int y){
    if (y < 0||y>2020)
        throw WrongInput();
    else
        year =y;
}
void Date::output(){
    cout << month <<"/"<<day<<"/"<<year<<endl;
    string nameMonth;
    if (month ==1)
        nameMonth = "January";
    if (month ==2)
        nameMonth = "February";
    if (month ==3)
        nameMonth = "March";
    if (month ==4)
        nameMonth = "April";
    if (month ==5)
        nameMonth = "May";
    if (month ==6)
        nameMonth = "June";
    if (month ==7)
        nameMonth = "July";
    if (month ==8)
        nameMonth = "August";
    if (month ==9)
        nameMonth = "September";
    if (month ==10)
        nameMonth = "October";
    if (month ==11)
        nameMonth = "November";
    if (month ==12)
        nameMonth = "December";
    cout << nameMonth << " "<<day<<", "<<year <<endl;
    cout << day<<" "<<nameMonth<<" "<<year<<endl;
}