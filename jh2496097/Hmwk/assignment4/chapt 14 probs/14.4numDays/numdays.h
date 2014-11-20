/* 
 * File:   numdays.h
 * Author: Jonathan
 *
 * Created on November 2, 2014, 11:50 PM
 */

#ifndef NUMDAYS_H
#define	NUMDAYS_H
class NumDays{
    private:
        float days;
        int hours;
        void calcDays();
    public:
        //NumDays();
        NumDays();
        NumDays( int);
        //void calcDays();
        void output();
        //mutators
        void setDays(float);
        void setHours(int);
        //accessors
        float getDays() const;
        int getHours() const;
        //overloading
        NumDays operator + (const NumDays &);
        NumDays operator - (const NumDays &);
        NumDays operator ++();//pre
        NumDays operator ++(int);//post
        NumDays operator --();//pre
        NumDays operator --(int);//post
};


#endif	/* NUMDAYS_H */

