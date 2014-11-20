/* 
 * Jonathan Holt
 * C++ objects
 * assignment 4
 * i certify this is my work
 * Created on November 2, 2014, 8:31 PM
 */

#include <cstdlib>
#include <iostream>

#include "feetinches.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cout << "This program is an extension of the books class of feet inches"
            <<endl << "has a copy constructor and creates + - * operator "
            "functions." <<endl<< " First shows automatic then lets user input"
            " some values." << endl;
    Feetinches box1(10, 11), box2, box3;
    cout << "Box 1" <<endl;
    box1.output();
    box2 = box1;
    cout <<"Copy box2"<<endl;
    box2.output();
    cout << "Box3 box1 + box2"<<endl;
    box3 = box1 + box2;
    box3.output();
    cout << "Box3 box3 - box2"<<endl;
    box3 = box3 - box2;
    box3.output();
    cout << "Box3 box1 * box2"<<endl;
    box3 = box1 * box2;
    box3.output();
    
    //user input
    int feet, inches;
    cout << "\n\nEnter Feet: " ;
    cin >> feet;
    cout << "Enter inches: ";
    cin >> inches;
    box1.setFeet(feet);
    box1.setInches(inches);
    box2 = box1;
    cout <<"Copy box2"<<endl;
    box2.output();
    cout << "Box3 box1 + box2"<<endl;
    box3 = box1 + box2;
    box3.output();
    cout << "Box3 box3 - box2"<<endl;
    box3 = box3 - box2;
    box3.output();
    cout << "Box3 box1 * box2"<<endl;
    box3 = box1 * box2;
    box3.output();
    return 0;
}

