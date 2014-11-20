/* 
 * File:   parkingticket.h
 * Author: Jonathan
 *
 * Created on November 9, 2014, 5:59 PM
 */

#ifndef PARKINGTICKET_H
#define	PARKINGTICKET_H
#include "parkedcar.h"
#include "parkingmeter.h"
#include "policeofficer.h"
class ParkingTicket{
    private:
        int ticket;
        ParkedCar car;
        ParkingMeter meter;
        PoliceOfficer officer;
    public:
        ParkingTicket (string, string, string, string, int, int);
        int getTicket();
        void makeReport(string, string, string, string, int, int, string,
        string);
        //void showPolice(const PoliceOfficer &obj);
};


#endif	/* PARKINGTICKET_H */

