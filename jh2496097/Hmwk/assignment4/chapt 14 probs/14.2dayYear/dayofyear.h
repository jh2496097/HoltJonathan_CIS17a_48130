/* 
 * File:   dayofyear.h
 * Author: Jonathan
 *
 * Created on November 2, 2014, 9:38 PM
 */

#ifndef DAYOFYEAR_H
#define	DAYOFYEAR_H
#include <string>
using namespace std;
class DayofYear{
    private:
        int day;
        string month;
        int number;
    public:
        DayofYear(int);
        void setDay (int);
        string setMonth (int);
        void print()const;
        void calc(int);
};
  

#endif	/* DAYOFYEAR_H */

