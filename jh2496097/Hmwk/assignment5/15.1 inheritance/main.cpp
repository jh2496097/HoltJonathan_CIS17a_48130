/* 
 * Jonathan Holt
 * C++ objects
 * assignment 4
 * i certify this is my work
 * Created on November 25, 2014, 10:18 AM
 */

#include <cstdlib>
#include "productionworker.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cout << "The program is used to show inheritance from employee class \n"
            "to production worker class." ;
    cout << "Utilizes exceptions..." <<endl << endl;
    //ProductionWorker emp1;<<endl << endl
    float hourly;
    cout << "Enter the hourly wage for the yourself: " <<endl;
    cin >> hourly;
    try{
       ProductionWorker emp1 (1, hourly, "Jonathan", "12345", "03/10/07");
    
        cout << "Employee 1:"<<endl;
        cout << "Name: " << emp1.getName() <<endl;
        cout << "I.D.: " << emp1.getEmpNum() <<endl;
        cout << "Hire: " << emp1.getHire() <<endl;
        cout << "Hourly: " <<fixed<<setprecision(2)<< emp1.getHourly() << endl;
        cout << "Shift: " << emp1.getShift() << endl;
    
        if (emp1.getShift() == 1)
            cout << "Day Shift"<<endl;
        else if (emp1.getShift() == 2)
            cout << "Night Shift"<<endl;
        else
            cout << "Invalid input for shift"<<endl;
    }
    catch (ProductionWorker::WrongInput){
        cout << "Entered an invalid input for one of the data types in the "
                "class."<<endl;
        //cout <<"Program terminated."<<endl<<endl<<endl;
    }
    return 0;
}

