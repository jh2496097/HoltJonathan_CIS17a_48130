/* 
 * Jonathan Holt
 * C++ objects
 * HW 2
 * i certify this is my work
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

/*
 * 
 */
int *p(int size);

int main(int argc, char** argv) {

    
    int size =0;
    int *array;
    cout << "Enter a number to represent the size of a dynamic array: " << endl;
    cin >> size;
    while (size < 1)
    {
        cout << "Enter a number bigger than 0." << endl;
        cin >> size;
    }
    array = p(size);
    
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
    delete [] array;
    return 0;
}
/* This function takes in a number to represent the size a dynamically 
 * created array/ptr. returns the new dynamic array.
 */
int *p(int size)
{
    int *ptr = new int [size];
    return ptr;
}