/**
 * Jonathan Holt
 * parkingticket implementation
 */
#include "parkingticket.h"
#include "parkedcar.h"
#include "parkingmeter.h"
#include "policeofficer.h"
#include <iostream>
ParkingTicket::ParkingTicket(string m, string mdel, string l, string c, 
        int mins, int paid){
    car.setAll(mins, m, mdel, l, c);
    meter.setPaidM(paid);   
    
}
int ParkingTicket::getTicket(){
    int checkTime;
    int parkedM = car.getMins();
    int paidM = meter.getPaidM();
    ticket = 0;
    //cout << "parkd mins: " << parkedM<<endl;
    //cout << "paid mins: " << paidM<<endl;
    //if (car.getMins() > meter.getPaidM())
    if (parkedM > paidM)
        ticket += 25;
    
    checkTime = parkedM - paidM;
    while (checkTime >= 60){
        ticket += 10;
        checkTime -=  60;
    }    
    return ticket;
}
void ParkingTicket::makeReport(string m , string mdel, string l , string c , 
        int mins, int paidMins, string name , string badge){
    car.setAll(mins, m, mdel, l, c);
    meter.setPaidM(paidMins);
    officer.setName (name);
    officer.setBadge (badge);
    car.output();
    cout << "Paid mins: " << paidMins << "   Parked mins: " <<mins<< endl;
    cout << "Officer: " << name << "   Badge: " << badge << endl;
}