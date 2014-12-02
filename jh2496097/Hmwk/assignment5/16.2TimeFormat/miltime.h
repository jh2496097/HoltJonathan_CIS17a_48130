/* 
 * File:   miltime.h
 * Author: Jonathan
 *
 * Created on November 28, 2014, 1:28 PM
 */

#ifndef MILTIME_H
#define	MILTIME_H
class MilTime:public Time{
    private:
        int milHours;
        int milMins;
    public:
        class BadHours{};
        class BadSeconds{};
        MilTime():Time(){milHours =0; milMins=0;}
        MilTime(int,int,int,int,int);
        void setTime(int,int,int,int,int);
        int getMHours(){return milHours;}
        int getMMins(){return milMins;}
};


#endif	/* MILTIME_H */

