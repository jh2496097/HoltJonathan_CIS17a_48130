/**
 * Jonathan Holt
 * numbers cpp file
 */
#include "mortgage.h"
#include <cmath>
Mortgage::Mortgage(){
    payment =0;
    year =0;
    loan =0;
    rate =0;
}
void Mortgage::setLoan(float l){
    if (l < 0)
        loan =0;
    else
        loan =l;
}
void Mortgage::setRate(float r){
    rate =r;
}
void Mortgage::setYrs(int y){
    if (y < 1)
        year = 1;
    else
        year =y;
}
float Mortgage::Pay(){
    float num = (1+(rate/12));
    float term = pow(num, 12*year);
    float p = (loan*(rate/12)*term)/(term-1);

    payment = p;
    return p;
}
float Mortgage::getPay() const{
    return payment;
}
float Mortgage::getLoan() const{
    return loan;
}
float Mortgage::getRate() const{
    return rate;
}
int Mortgage::getYear() const{
    return year;
}
float Mortgage::monthPay() const{
    return loan-payment;
}