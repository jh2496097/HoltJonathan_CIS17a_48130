/* 
 * File:   parkingmeter.h
 * Author: Jonathan
 *
 * Created on November 6, 2014, 10:49 AM
 */

#ifndef PARKINGMETER_H
#define	PARKINGMETER_H
class ParkingMeter{
    private:
        int paidMins;
    public:
        ParkingMeter(int);
        ParkingMeter();
        //mutators
        void setPaidM(int m);//{ paidMins =m;}
        //setters
        int getPaidM() const{ return paidMins;}
};


#endif	/* PARKINGMETER_H */

