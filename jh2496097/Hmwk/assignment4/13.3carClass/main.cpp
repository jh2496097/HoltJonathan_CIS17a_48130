/* 
 * Jonathan Holt
 * C++ objects
 * assignment 4
 * i certify this is my work
 * Created on November 1, 2014, 5:39 PM
 */

#include <cstdlib>
#include <iomanip>
#include "car.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cout << "This program makes a class instance of a car uses a constructor to"
            " define." << endl<< "Program can also be used to set different "
            "types of definitions for an"<<endl<<
            "instance." << " Will show a default constructor car as well!" <<
            endl;
    cout <<"Takes into check user validation with making sure negative numbers"
            << endl << "for speed are not inputted. Notice with brake function"
            " being " << endl<< "called 100 times. Checks to make sure car year"
            " is between 1930 and higher." <<endl<<endl;
    //initializing object car1
    Car car1("Porsche", 2000, 80);
    cout <<setw(15) <<"Make"  <<setw(12)<<"Year Model"<<setw(10)<<"Speed"
            <<endl;
    cout << setw(15) <<car1.getMake()<<setw(12)<<car1.getYear()<<
            setw(10)<< car1.getSpeed() <<endl;
    for (int i=0; i < 5; i++){
        car1.accelerate();
    }
    cout<<"Calling function accelerate 5 times!"<<endl;
    cout << setw(15) <<car1.getMake()<<setw(12)<<car1.getYear()<<
            setw(10)<< car1.getSpeed() <<endl;
    for (int i=0; i < 5; i++){
        car1.brake();
    }
    cout<<"Calling function brake 5 times!"<<endl;
    cout << setw(15) <<car1.getMake()<<setw(12)<<car1.getYear()<<
            setw(10)<< car1.getSpeed() <<endl;
    for (int i=0; i < 100; i++){
        car1.brake();
    }
    cout<<"Calling function brake 100 times!"<<endl;
    cout << setw(15) <<car1.getMake()<<setw(12)<<car1.getYear()<<
            setw(10)<< car1.getSpeed() <<endl;
    //initializing car2
    Car car2;
    /*car2.setMake("Chevy");
    car2.setSpeed(-123213) ;
    car2.setYear(1929);*/
    cout<<"Showing car 2 default constructor...." <<endl;
    cout << setw(15) <<car2.getMake()<<setw(12)<<car2.getYear()<<
            setw(10)<< car2.getSpeed() <<endl;
    return 0;
}

