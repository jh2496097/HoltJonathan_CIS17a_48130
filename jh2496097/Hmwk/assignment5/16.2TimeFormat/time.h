/* 
 * File:   time.h
 * Author: Jonathan
 *
 * Created on November 28, 2014, 1:21 PM
 */

#ifndef TIME_H
#define	TIME_H

class Time{
    private:
        int hour;
        int min;
        int sec;
    public:
        Time();
        Time(int,int ,int);
        void setHour(int h){hour = h;}
        void setMin (int m){min = m;}
        void setSec (int s){sec = s;}
        int getHour(){return hour;}
        int getMin(){return min;}
        int getSec(){return sec;}
};

#endif	/* TIME_H */

