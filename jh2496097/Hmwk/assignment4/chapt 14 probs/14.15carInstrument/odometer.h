/* 
 * File:   odometer.h
 * Author: Jonathan
 *
 * Created on November 17, 2014, 2:50 PM
 */

#ifndef ODOMETER_H
#define	ODOMETER_H
#include "fuelgauge.h"
class Odometer{
    private:
        FuelGauge car;
        int mileage;
        
    public:
        Odometer();
        Odometer (int,FuelGauge &);
        
        void setMiles(int);
        int getMiles()const;
        
        Odometer operator ++ (int);
};


#endif	/* ODOMETER_H */

