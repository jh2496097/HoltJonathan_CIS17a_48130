/* 
 * File:   simplevector.h
 * Author: Jonathan
 *
 * Created on November 28, 2014, 3:03 PM
 */

#ifndef SIMPLEVECTOR_H
#define	SIMPLEVECTOR_H

#include <iostream>
#include <new>
template <class T>
class SimpleVector{
    private:
        T *aptr;
        int arraySize;
        void memError();
        void subError();
    public:
        SimpleVector(){aptr =0, arraySize =0;}
        SimpleVector(int);
        //copy
        SimpleVector (const SimpleVector &);
        ~SimpleVector ();
        int size()const{return arraySize;}
        T getElementAt(int);
        T &operator[](const int &);
        
            
};
#endif	/* SIMPLEVECTOR_H */

