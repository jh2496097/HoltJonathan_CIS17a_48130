//implementation of class sort vector

#include "sortvector.h"

template <class T>
SortableVector<T>::SortableVector(const SortableVector& obj) :
        SimpleVector<T>(obj.size()){
    for (int i =0; i < this->size();i++)
        this->operator [](i) = obj [i];
}

template <class T>
int SortableVector<T>::findItem(const T item){
    for (int i = 0; i <= this->size(); i++){
        //if (getElementAt(i) == item)
        //    return i;
    }
    return -1;
}