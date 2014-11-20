/**
 * Jonathan Holt
 * parkedcar implementation
 */
#include "parkedcar.h"
#include <iostream>
#include <iomanip>
//using namespace std;
ParkedCar::ParkedCar(){
    //set everything to nothing
    mins =0;
    color ="";
    make ="";
    model ="";
    license ="";
}
ParkedCar::ParkedCar(int m, string mk, string mdel, string c, string l){
    mins = m;
    make = mk;
    model = mdel;
    color = c;
    license = l;
}
void ParkedCar::setAll(int m, string mk, string mdel, string c, string l){
    mins = m;
    make = mk;
    model = mdel;
    color = c;
    license = l;
}
void ParkedCar::setMins(int m){
    if (m < 0){
        mins = -1;
    }
    else
        mins =m;
}
void ParkedCar::setMake(string mak){
    make = mak;
}
void ParkedCar::setModel(string mdel){
    model = mdel;
}
void ParkedCar::setLicense(string l){
    if (l.size() != 7){
        license = "invalid license";
    }
    else
        license = l;
}
void ParkedCar::setColor(string c){
    color = c;
}
void ParkedCar::output() const{
    cout << "The cars information is:"<<endl;
    cout <<setw(15)<<"Car Model"<<setw(15)<<
            "Car Make"<<setw(15)<<"Car License"<<setw(15)<<"Car Color"<<endl;
    cout <<setw(15)<<model<<setw(15)<<
            make<<setw(15)<<license<<setw(15)<<color<<endl;
}