/* 
 * File:   feetinches.h
 * Author: Jonathan
 *
 * Created on November 2, 2014, 8:32 PM
 */

#ifndef FEETINCHES_H
#define	FEETINCHES_H
#include <iostream>

class Feetinches{
    private:
        int feet;
        int inches;
        void simplify();
    public:
        Feetinches();
        Feetinches (int, int);
        //copy
        Feetinches (const Feetinches &);
        //destructor
        //~Feetinches ();
        void setFeet(int);
        void setInches(int);
        //accessor
        int getFeet() const;
        int getInches() const;
        void output () const;
        //overload
        Feetinches operator + (const Feetinches &);
        Feetinches operator - (const Feetinches &);
        Feetinches operator * (const Feetinches &);
};


#endif	/* FEETINCHES_H */

