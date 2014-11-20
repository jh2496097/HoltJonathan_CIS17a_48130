/**
 * Jonathan Holt
 * person feetinches implementation
 */
#include "feetinches.h"
#include <cstdlib>
using namespace std;
//constructors
Feetinches::Feetinches(){
    feet =0;
    inches =0;
}
Feetinches::Feetinches(int f, int i){
    if (f < 0)
        feet = 0;
    else 
        feet =f;
    if (i < 0)
        inches =0;
    else
        inches =i;
}
//copy
Feetinches::Feetinches(const Feetinches& obj){
    feet = obj.feet;
    inches = obj.inches;
}
//destructor
//none
void Feetinches::simplify(){
    if (inches >= 12){
        feet += (inches /12);
        inches = inches % 12;
    }
    else if (inches <0){
        feet -= ((abs(inches)/ 12)+1);
        inches = 12 - (abs(inches)%12);
    }
}
//mutators
void Feetinches::setFeet(int f){
    if (f < 0)
        feet = 0;
    else 
        feet =f;
}
void Feetinches::setInches(int i){
    if (i < 0)
        inches =0;
    else
        inches =i;
}
//accessor
int Feetinches::getFeet() const{
    return feet;
}
int Feetinches::getInches() const{
    return inches;
}
void Feetinches::output() const{
    cout << feet << " Feet and " << inches << " Inches"<<endl;
}
//operators
Feetinches Feetinches::operator +(const Feetinches&right){
    Feetinches temp;
    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();
    return temp;
}
Feetinches Feetinches::operator -(const Feetinches&right){
    Feetinches temp;
    temp.inches = inches - right.inches;
    temp.feet = feet - right.feet;
    temp.simplify();
    return temp;
}
Feetinches Feetinches::operator *(const Feetinches&right){
    Feetinches temp;
    temp.inches = inches * right.inches;
    temp.feet = feet * right.feet;
    temp.simplify();
    return temp;
}