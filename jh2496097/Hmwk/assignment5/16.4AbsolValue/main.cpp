/* 
 * Jonathan Holt
 * C++ objects
 * assignment 4
 * i certify this is my work
 * Created on November 28, 2014, 2:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
T absolValue (T num){
    if (num < 0)
        return num - (num*2);
    else
        return num;
}
/*
 * 
 */
int main(int argc, char** argv) {

    cout <<"This program uses templates to show that overloading functions is "
            "not \nnecessary when you have templates! Gives the absolute value"
            "of numbers."<<endl<<endl;
    int intVal;
    float floatVal;
    
    cout << "Enter a integer value: " ;
    cin >> intVal;
    cout << "Enter a decimal value: ";
    cin >> floatVal;
    
    cout <<"\nThis is their absolute values..."<<fixed<<setprecision(3)<<
            endl<<endl;
    cout << absolValue (intVal) << " and " << absolValue (floatVal) <<endl
            <<endl<<endl;
    return 0;
}

