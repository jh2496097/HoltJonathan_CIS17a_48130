/**
 * Jonathan Holt
 * person feetinches implementation
 */
#include "numdays.h"
#include <iostream>
using namespace std;
NumDays::NumDays(){
    days = 0;
    hours = 0;
}
NumDays::NumDays(int h){
    if (h < 1)
        hours = 0;
    else
        hours =h;
    days = hours/8.0;
}
void NumDays::calcDays(){
    days = hours / 8.0;
}
void NumDays::output(){
    cout << "The hours is " << hours << " so days is " << days<< "."<<endl;
}
void NumDays::setDays(float d){
    days = d;
}
void NumDays::setHours(int h){
    hours =h;
}
float NumDays::getDays() const{
    //days = hours /8.0;
    return hours/8.0;
}
int NumDays::getHours() const{
    return hours;
}
NumDays NumDays::operator +(const NumDays&obj){
    NumDays temp;
    temp.days = days + obj.days;
    temp.hours= hours + obj.hours;
    //calcDays();
    return temp;
}
NumDays NumDays::operator -(const NumDays&obj){
    NumDays temp;
    temp.days = days - obj.days;
    temp.hours= hours - obj.hours;
    //calcDays();
    return temp;
}
NumDays NumDays::operator ++(){
    ++hours;
    calcDays();
    return *this;
}
NumDays NumDays::operator ++(int){
    NumDays temp (hours);
    hours++;
    calcDays();
    return temp;
}
NumDays NumDays::operator --(){
    --hours;
    calcDays();
    return *this;
}
NumDays NumDays::operator --(int){
    NumDays temp (hours);
    hours--;
    calcDays();
    return temp;
}
