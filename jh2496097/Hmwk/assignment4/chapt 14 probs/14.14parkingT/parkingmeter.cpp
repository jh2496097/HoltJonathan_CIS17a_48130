/**
 * Jonathan Holt
 * parkingmeter implementation
 */
#include "parkingmeter.h"
ParkingMeter::ParkingMeter(){
    paidMins = 0;
}
ParkingMeter::ParkingMeter(int m){
    if (m < 0)
        paidMins =0;
    else
        paidMins =m;
}
void ParkingMeter::setPaidM(int m){
    if (m < 0)
        paidMins =0;
    else
        paidMins =m;
}
