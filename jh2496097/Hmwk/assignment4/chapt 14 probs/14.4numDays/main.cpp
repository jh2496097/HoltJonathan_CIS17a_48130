/* 
 * Jonathan Holt
 * C++ objects
 * assignment 4
 * i certify this is my work
 * Created on November 2, 2014, 11:50 PM
 */

#include <cstdlib>
#include "numdays.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cout << "This program converts hours into amount of work days worked."<<endl
            <<"Takes input of amount of hours worked and then outputs how many"
            << endl<<"days should have been worked. Typical work day is 8 hours"
            <<endl<<"so that is the divisor." <<" Implements the operators + - "
            "++ --"<<endl<<endl;
    NumDays day1(18);
    NumDays day2(10);
    NumDays day3;

    day1.output();
    day2.output();
    
    day3 = day1 + day2;
    cout << "Day 1 + Day 2!!" <<endl;
    day3.output();
    
    day3 = day1 - day2;
    cout << "Day 1 - Day 2!!" <<endl;
    day3.output();
    
    day3++;
    cout << "Day 3++!!" <<endl;
    day3.output();
    
    day3--;
    cout << "Day 3--!!" <<endl;
    day3.output();
    return 0;
}

