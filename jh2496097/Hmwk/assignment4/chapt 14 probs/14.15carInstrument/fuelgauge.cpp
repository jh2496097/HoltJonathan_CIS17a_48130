/**
 * Jonathan Holt
 * fuel Gauge implementation
 */
#include "fuelgauge.h"
#include <iostream>
using namespace std;
FuelGauge::FuelGauge(){
    gallons = 0;
}
FuelGauge::FuelGauge(int n){
    if (n < 0)
        gallons =0;
    if (n > 15)
        gallons = 15;
    else
        gallons = n; 
}
FuelGauge::FuelGauge(FuelGauge &obj){
    gallons = obj.gallons;
}
void FuelGauge::setGallons(int g){
    if (g < 0)
        gallons =0;
    if (g < 15)
        gallons = 15;
    else
        gallons = g; 
}
int FuelGauge::getGallons() const{
    return gallons;
}
FuelGauge FuelGauge::operator ++(int){
    if (gallons < 15){
        gallons++;
        return *this;
    }
    else{
        cout<<"Tank gallon is full cannot exceed 15 gallons." <<endl;
    }
}
FuelGauge FuelGauge::operator --(int){
    if (gallons > 0){
        gallons--;
        return *this;
    }
    else{
        cout<<"Tank gallon is empty." <<endl;
        gallons =-1;
    }
}