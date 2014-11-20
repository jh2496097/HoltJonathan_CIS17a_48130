/* 
 * File:   policeofficer.h
 * Author: Jonathan
 *
 * Created on November 9, 2014, 6:52 PM
 */

#ifndef POLICEOFFICER_H
#define	POLICEOFFICER_H
//#include "parkedcar.h"
//#include "parkingmeter.h"
//#include "parkingticket.h"
#include <string>
using namespace std;
class PoliceOfficer{
    private:
        string name;
        string badgeNum;
        //ParkedCar car;
    public:
        PoliceOfficer (string, string);
        PoliceOfficer ();
        void setName (string);     
        void setBadge (string);
};


#endif	/* POLICEOFFICER_H */

