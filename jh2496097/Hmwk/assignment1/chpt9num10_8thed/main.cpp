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
int fillArr (int [], int);
void outputArr (const int [], int );
int *copyArrR (int arr[], int SIZE);

int main(int argc, char** argv) {
    
    const int SIZE = 20;
    int arr[SIZE] = {};
    int *newArr;
    cout << "Here is an array with some values. " << endl;
    arr[SIZE] = fillArr (arr, SIZE);
    outputArr (arr, SIZE);
    cout << endl << endl;
    cout << "Here is a copied pointer with values reversed. " << endl;
    newArr = copyArrR (arr, SIZE);
    outputArr (newArr, SIZE);
    cout << endl;
    
    delete [] newArr;
    newArr = NULL;
    return 0;
}
/*
 * This function takes in an array and turns it into a dynamic array. It fills
 * the array with values ranging from 0 to 4. Loops to fill each element then
 * finally returns the final dynamic ptr/arr
 */
int fillArr (int arr[], int SIZE)
{
    //loop to fill array
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = i % 16;
    }
    return arr[SIZE];
}
/*
 * This function serves the purpose of outputting a ptr/array to the console
 * takes a loop and outputs every element.
 */
void outputArr (const int arr[], int SIZE)
{
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        cout << left << setw(6) << arr[i];
        count++;
        if (count == 8)
        {
            cout << endl;
            count = 0;
        }
    }
}
/*
 * This function takes in an array and then copies it to another but the 
 * contents will be copied in reverse order. Both will be same size and returns
 * a new array.
 */
int *copyArrR (int arr[], int SIZE)
{
    int *arr2 = new int [SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        arr2[i] = arr[SIZE-1 -i];
    }
    return arr2;
}