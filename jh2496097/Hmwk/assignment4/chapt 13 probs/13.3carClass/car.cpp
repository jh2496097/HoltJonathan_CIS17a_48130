/**
 * Jonathan Holt
 * car class implementation
 */
#include "car.h"
using namespace std;
Car::Car(){
    yearModel =0;
    make = "null";
    speed = 0;
}
Car::Car(string m, int year, int s){
    make = m;
    if (yearModel < 1930){
        yearModel =0;
    }
    else
        yearModel = year;
    if (speed < 0){
        speed =0;
    }
    else
        speed = s;
}
void Car::setMake(string m){
    make = m;
}
void Car::setSpeed(int s){
    if (s < 0)
        s =0;
    else
        speed = s;
}
void Car::setYear(int year){
    if (year < 1930 )
        year =0;
    else
        yearModel = year;
}
void Car::brake(){
    if (speed <= 0){
        speed =0;
    }
    else 
        speed -= 5;
}
string Car::getMake() const{
    return make;
}
int Car::getSpeed() const{
    return speed;
}
int Car::getYear() const{
    return yearModel;
}