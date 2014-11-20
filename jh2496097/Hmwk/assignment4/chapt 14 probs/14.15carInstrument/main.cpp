/* 
 * Jonathan Holt
 * C++ objects
 * assignment 4
 * i certify this is my work
 * Created on November 17, 2014, 2:49 PM
 */

#include <cstdlib>
#include "fuelgauge.h"
#include "odometer.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    FuelGauge test(12);
    cout << "Gallons: " << test.getGallons()<<endl;
    test++;
    cout << "Gallons: " << test.getGallons()<<endl;
    test++;test++;test++;
    cout << "Gallons: " << test.getGallons()<<endl;
    for (int i=0; i < 18; i++)
        test--;
    cout << "Gallons: " << test.getGallons()<<endl;
    
    
    
    FuelGauge car1(15);
    Odometer car(100000, car1);
    int totalM;
    cout<<"\n\n\nCAR 1:"<<endl;
    cout << "Gallons: " << car1.getGallons()<<endl;
    cout << "Mileage: " << car.getMiles()<<endl;
    for (int miles=0; miles < 400;miles++){
        car++;
        totalM = miles;
        if (miles%24 == 0){
            car1--;
        }
        if (car1.getGallons() == -1){
            cout <<"Car ran out of gas at odometer reading: " << 
                    car.getMiles()-1 << endl;
            miles+=100000;
        }       
    }
    cout << "Total miles traveled: " << totalM <<endl;
    cout << "Gallons: " << car1.getGallons()<<endl;
    cout << "Mileage: " << car.getMiles()-1<<endl;
    
    
    FuelGauge car2(5);
    Odometer car_2(999960, car2);
    //int totalM;
    cout<<"\n\n\nCAR 2:"<<endl;
    cout << "Gallons: " << car2.getGallons()<<endl;
    cout << "Mileage: " << car_2.getMiles()<<endl;
    for (int miles=0; miles < 400;miles++){
        car_2++;
        totalM = miles;
        if (miles%24 == 0){
            car2--;
        }
        if (car2.getGallons() == -1){
            cout <<"Car ran out of gas at odometer reading: " <<
                    car_2.getMiles()-1 << endl;
            miles+=100000;
        }       
    }
    cout << "Total miles traveled: " << totalM <<endl;
    cout << "Gallons: " << car2.getGallons()<<endl;
    cout << "Mileage: " << car_2.getMiles()-1<<endl;
    return 0;
}

