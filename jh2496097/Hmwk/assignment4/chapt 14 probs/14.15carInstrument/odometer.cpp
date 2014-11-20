/**
 * Jonathan Holt
 * odometer implementation
 */
#include "odometer.h"
#include <iostream>
using namespace std;
Odometer::Odometer(){
    mileage =0;
}
Odometer::Odometer(int m, FuelGauge &obj){
    if (m > 0)
        mileage = m;
    else 
        mileage =0;
    
    car = obj;
}

void Odometer::setMiles(int m){
    if (m > 0)
        mileage = m;
    else 
        mileage =0;
}
int Odometer::getMiles() const{
    return mileage;
}
Odometer Odometer::operator ++(int){
    mileage++;
    if (mileage == 1000000){
        mileage=0;
        cout<<"Odometer set back to 0."<<endl;
    }
    //calcMiles(car);
    return *this;
}