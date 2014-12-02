/* 
 * Jonathan Holt
 * C++ objects
 * assignment 4
 * i certify this is my work
 * Created on November 28, 2014, 12:12 PM
 */

#include <cstdlib>
#include "date.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cout << "This program utilizes the exception with the date class. if "
            "negative \nnumbers is entered for year or over 2020 an exception"
            " is thrown\nand same with days and months if number is not within "
            "correct days(1-31) \nor months (1-12)."<<endl<<endl<<endl;
    Date myDate;
    try{
        myDate.setDay(30);
        myDate.setMonth(12);
        myDate.setYear(2010);
        myDate.output();
    }
    catch (Date::WrongInput){
        cout << "Entered an invalid input for one of the data types in date "
                "class."<<endl;
        cout <<"Program terminated."<<endl<<endl<<endl;
    }
    
    
    return 0;
}

