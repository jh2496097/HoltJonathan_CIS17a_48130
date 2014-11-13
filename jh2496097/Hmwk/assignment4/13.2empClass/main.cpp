/* 
 * Jonathan Holt
 * C++ objects
 * assignment 4
 * i certify this is my work
 * Created on November 1, 2014, 3:34 PM
 */

#include <cstdlib>
#include "employee.h"
#include <iostream>
#include <iomanip>
using namespace std;


int main(int argc, char** argv) {

    cout <<"This program gets a list of employees and their information" <<endl;
    cout <<"Then outputs all the information. Takes into account invalid"<<
            endl<< "input for number if number is negative or greater than "
            "100000" << endl << "as seen with employee 1"
            " i set id to a negative number."<<endl;
    cout<< "Since it is a negative number, ID is set to 0."<<endl;
    cout <<"Default constructor sets everything to nothing." <<endl<<endl;
    //first employee
    Employee stu1("Susan Meyers", -47899, "Accounting", " Vice President");
    //second employee
    Employee stu2("Mark Jones", 99999);
    stu2.setDepart("IT");
    stu2.setTitle("Programmer");
    //third employee
    Employee stu3;
    stu3.setName("Joy Rogers");
    stu3.setNum(81774);
    stu3.setDepart("Manufacturing");
    stu3.setTitle("Engineer");
    Employee stu4;
    //stu1 ("Big John", 102300, "Accounting", "President");
    
    cout <<setw(18) <<"NAME"  <<setw(10)<<"ID number"<<setw(18)<<"DEPARTMENT"<<
            setw(18)<<"POSITION "<<endl;
    cout <<setw(18)<<stu1.getName()<<setw(10) << stu1.getID()<<setw(18)<<
            stu1.getDepart()<<setw(18) << stu1.getTitle() << endl;
    cout <<setw(18)<<stu2.getName()<<setw(10) << stu2.getID()<<setw(18)<<
            stu2.getDepart()<<setw(18) << stu2.getTitle() << endl;
    cout <<setw(18)<<stu3.getName()<<setw(10) << stu3.getID()<<setw(18)<<
            stu3.getDepart()<<setw(18) << stu3.getTitle() << endl;
    cout <<"**************Showing default constructor******************"<<endl;
    cout <<setw(18)<<stu4.getName()<<setw(10) << stu4.getID()<<setw(18)<<
            stu4.getDepart()<<setw(18) << stu4.getTitle() << endl;
    return 0;
}

