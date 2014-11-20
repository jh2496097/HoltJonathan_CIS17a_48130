/* 
 * File:   mortgage.h
 * Author: Jonathan
 *
 * Created on November 1, 2014, 10:34 PM
 */

#ifndef MORTGAGE_H
#define	MORTGAGE_H
class Mortgage{
    private:
        float payment;
        float loan;
        float rate;
        int year;
    public:
        Mortgage();
        //setters
        float Pay();
        void setLoan(float);
        void setRate(float);
        void setYrs(int);
        //getters
        float getPay() const;
        float getRate() const;
        int getYear() const;
        float monthPay() const;
        float getLoan() const;
};


#endif	/* MORTGAGE_H */

