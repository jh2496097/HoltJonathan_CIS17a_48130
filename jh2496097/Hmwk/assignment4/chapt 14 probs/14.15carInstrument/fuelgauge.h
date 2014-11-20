/* 
 * File:   fuelgauge.h
 * Author: Jonathan
 *
 * Created on November 17, 2014, 2:49 PM
 */

#ifndef FUELGAUGE_H
#define	FUELGAUGE_H
class FuelGauge{
    private:
        int gallons;
    public:
        FuelGauge();
        FuelGauge(int);
        FuelGauge(FuelGauge &);
        void setGallons(int);
        int getGallons()const;
        FuelGauge operator ++ (int);
        FuelGauge operator -- (int);
};


#endif	/* FUELGAUGE_H */

