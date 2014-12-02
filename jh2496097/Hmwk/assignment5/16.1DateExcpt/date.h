/* 
 * File:   date.h
 * Author: Jonathan
 *
 * Created on November 28, 2014, 12:13 PM
 */

#ifndef DATE_H
#define	DATE_H

class Date{
    private:
        int month;
        int day;
        int year;
    public:
        class WrongInput{};
        Date();
        Date (int, int ,int);
        void setMonth(int);
        void setDay (int);
        void setYear(int);
        int getMonth(){return month;}
        int getDay(){return day;}
        int getYear(){return year;}
        void output();
};


#endif	/* DATE_H */

