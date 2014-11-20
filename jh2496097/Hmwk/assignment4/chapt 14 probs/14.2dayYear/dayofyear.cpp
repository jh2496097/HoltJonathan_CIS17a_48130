/**
 * Jonathan Holt
 * person dayofyear implementation
 */
#include "dayofyear.h"
#include <iostream>
using namespace std;

DayofYear::DayofYear(int num){
    calc(num);
}

void DayofYear::print() const{
    cout << "Day " << number << " would be " <<month<<" "<< day <<"."<<endl;
}
string DayofYear::setMonth(int num){
    string m;
    if (num ==0)
        m = "January";
    if (num ==1)
        m = "February";
    if (num ==2)
        m = "March";
    if (num ==3)
        m = "April";
    if (num ==4)
        m = "May";
    if (num ==5)
        m = "June";
    if (num ==6)
        m ="July";
    if (num ==7)
        m = "August";
    if (num ==8)
        m = "September";
    if (num ==9)
        m = "October";
    if (num ==10)
        m = "November";
    if (num ==11)
        m = "December";
    
    return m;
}
void DayofYear::setDay(int num){
    calc(num);
}
void DayofYear::calc(int num){
    if (num >= 1 && num <= 31){//spot>=0&&spot< size
        day =num % 1000;
        month = setMonth(0);
    }
    else if(num >= 32 && num <= 59){
        day =num % 31;
        month = setMonth(1);
    }
    else if(num >= 60 && num <= 90){
        day =num % 59;
        month = setMonth(2);
    }
    else if(num >= 91 && num <= 120){
        day =num % 90;
        month = setMonth(3);
    }
    else if(num >= 121 && num <= 151){
        day =num % 120;
        month = setMonth(4);
    }
    else if(num >= 152 && num <= 181){
        day =num % 151;
        month = setMonth(5);
    }
    else if(num >= 182 && num <= 212){
        day =num % 181;
        month = setMonth(6);
    }
    else if(num >= 213 && num <= 243){
        day =num % 212;
        month = setMonth(7);
    }
    else if(num >= 244 && num <= 273){
        day =num % 243;
        month = setMonth(8);
    }
    else if(num >= 274 && num <= 304){
        day =num % 273;
        month = setMonth(9);
    }
    else if(num >= 305 && num <= 334){
        day =num % 304;
        month = setMonth(10);
    }
    else if(num >= 335 && num <= 365){
        day =num % 334;
        month = setMonth(11);
    }
    else 
        day = 0;
    if (day ==0)
        month="invalid input";

    number = num;
}