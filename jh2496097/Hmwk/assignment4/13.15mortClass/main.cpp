/* 
 * Jonathan Holt
 * C++ objects
 * assignment 4
 * i certify this is my work
 * Created on November 1, 2014, 10:33 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "mortgage.h"
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Mortgage house1;
    house1.setYrs(10);
    house1.setRate(0.05);
    house1.setLoan(100000);
    float payment = house1.Pay();
    
    cout <<fixed<< setprecision(2);
    cout << "The payment for the month is: " << payment << endl;

    cout << "The loan was: " << house1.getLoan() << endl;
    cout << "The rate was: " << house1.getRate() <<endl;
    cout << "The amount of years to be paid was: " << house1.getYear() <<endl;

    float month = house1.monthPay();
    cout << "The loan at the end of the month is: " << month <<endl;
    return 0;
}

