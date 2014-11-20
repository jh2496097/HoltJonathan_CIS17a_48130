/* 
 * Jonathan Holt
 * C++ objects
 * assignment 4
 * i certify this is my work
 * Created on November 6, 2014, 10:27 AM
 */

#include <cstdlib>
#include "policeofficer.h"
#include "parkingticket.h"
#include "parkedcar.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cout <<"This program utilizes aggregation between 4 different types of"
            " classes.\nIt was very confusing at first but i figured"
            " out the 'has a' \nrelationship between all the classes. The"
            " program has three different \ninstances of a car and prompts"
            " user for issuing tickets \nas if they were the officer." <<endl
            <<endl;
    char c;
    ParkedCar car1(201, "Ford","Focus","red","123TP23");
    ParkedCar car2(100, "Ford", "F-150", "yellow", "321TP23");
    ParkedCar car3(1000, "Chevy", "Silverado", "blue", "654TP23");
    
    
    cout << "PARKED CAR 1"<<endl;
    ParkingTicket ticket("Ford", "Focus", "red", "123TP23", 302, 201);

    ticket.makeReport("Ford", "Focus", "red", "123TP23", 302, 201, 
            "Officer Brad", "44444");
    cout << "ISSUE TICKET???? Y for yes or anything else for no" <<endl;
    cin >> c;
    if (toupper(c) == 'Y'){
        int tickets = ticket.getTicket();
        cout << "TICKET: $" << tickets << endl;
        car1.output();
    }
    
    
    cout << "\n\n\nPARKED CAR 2"<<endl;
    ParkingTicket ticket2("Ford", "F-150", "yellow", "321TP23", 100, 100);

    ticket.makeReport("Ford", "F-150", "yellow", "321TP23", 100, 100, 
            "Officer Brad", "44444");
    cout << "ISSUE TICKET???? Y for yes or anything else for no" <<endl;
    cin >> c;
    if (toupper(c) == 'Y'){
        int tickets = ticket2.getTicket();
        cout << "TICKET: $" << tickets << endl;
        car2.output();
    } 
    
    
    cout << "\n\n\nPARKED CAR 3"<<endl;
    ParkingTicket ticket3("Chevy", "Silverado", "blue", "654TP23", 1000, 100);

    ticket.makeReport("Chevy", "Silverado", "blue", "654TP23", 1000, 100, 
            "Officer Brad", "44444");
    cout << "ISSUE TICKET???? Y for yes or anything else for no" <<endl;
    cin >> c;
    if (toupper(c) == 'Y'){
        int tickets = ticket3.getTicket();
        cout << "TICKET: $" << tickets << endl;
        car3.output();
    }    
    return 0;
}

