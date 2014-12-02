//implementation of simple vector class

#include "simplevector.h"
#include <new>
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
SimpleVector<T>::SimpleVector(int s){
    arraySize = s;
    //allocate memory
    try{
        aptr = new T [s];
    }
    catch (bad_alloc){
        memError();
    }
    //initialize
    for (int i =0; i < arraySize;i++)
        *(aptr + i) = 0;
}
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj){
    //copy
    arraySize = obj.arraySize;
    aptr = new T [arraySize];
    if (aptr ==0)
        memError();
    //copy over
    for (int i =0; i < arraySize;i++){
        *(aptr +i) = *(obj.aptr+i);
    }
}
template <class T>
SimpleVector<T>::~SimpleVector(){
    if (arraySize > 0)
        delete []aptr;
}
template <class T>
void SimpleVector<T>::memError(){
    cout << "Error with memory cannot allocate."<<endl;
    exit(EXIT_FAILURE);
}
template<class T>
void SimpleVector<T>::subError(){
    cout << "Error with subscript out of range."<<endl;
    exit(EXIT_FAILURE);
}
template <class T>
T SimpleVector<T>::getElementAt(int p){
    if (p < 0 || p >= arraySize)
        subError();
    else 
        return aptr[p];
}
template <class T>
T &SimpleVector<T>::operator [](const int &sub){
    if (sub < 0 || sub >=arraySize)
        subError();
    else
        return aptr[sub];
}