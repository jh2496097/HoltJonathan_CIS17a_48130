/* 
 * Jonathan Holt
 * C++ objects
 * assignment 4
 * i certify this is my work
 * Created on November 2, 2014, 9:37 PM
 */

#include <cstdlib>
#include "dayofyear.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cout<<"This program allows user to see which day of 1 to 365 would fall"
            " on\nthe calender date. I have a constructor setup for the class"
            " as well\nas a setter function. User may manually put"
            " which day he wants\nto know our simply enter it. Does a check"
            " for valid input.\n\n";
    DayofYear date(92);
    date.print();
    int number;
    cout << "\n\nEnter a day 1 thru 365 !\nI'll tell you what month and day"
            " that is: " <<endl;
    cin >> number;
    date.setDay(number);
    date.print();
    
    return 0;
}

