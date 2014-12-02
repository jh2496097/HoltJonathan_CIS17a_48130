/* 
 * File:   sortablevector.h
 * Author: Jonathan
 *
 * Created on November 28, 2014, 3:27 PM
 */

#ifndef SORTABLEVECTOR_H
#define	SORTABLEVECTOR_H
#include "simplevector.h"

template <class T>
class SortableVector : public SimpleVector<T>{
    public:
        SortableVector () : SimpleVector<T>(){}
        SortableVector (int s) : SimpleVector<T> (s){}
        SortableVector (const SortableVector &);
        void sort(const T);
        
};


#endif	/* SORTABLEVECTOR_H */

