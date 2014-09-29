/* 
 * Jonathan Holt
 * C++ objects
 * HW 2
 * i certify this is my work
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

int *fillArr (int *, int);
void outputArr (const int *, int);
void sortArr (int *, int);
int *mode (int *, int , int&);
float mean (int *, int);
float median (int *, int);

int main(int argc, char** argv) {

    int *modePtr;
    int *p;
    const int SIZE = 25;
    float meanAvg = 0;
    float medianNum=0;
    //filling ptr
    p = fillArr (p, SIZE);
    //output
    outputArr (p, SIZE);
    cout << endl << endl;
    //sorting
    sortArr (p, SIZE);
    //output
    outputArr (p, SIZE);
    
    int modeSize =0;
    modePtr = mode(p, SIZE, modeSize);
    cout << "\nThe mode(s) is: " << endl;
    outputArr (modePtr, modeSize);
    
    meanAvg = mean (p, SIZE);
    cout << "\nThe mean is: " << fixed << setprecision(3) <<
            endl << meanAvg;
    medianNum = median (p, SIZE);
    cout << "\nThe median is: " << fixed << setprecision(1) << endl;
    cout << medianNum << endl;
    
    //free up memory
    delete [] p;
    delete [] modePtr;
    return 0;
}
/*
 * This function takes in an array and turns it into a dynamic array. It fills
 * the array with values ranging from 0 to 4. Loops to fill each element then
 * finally returns the final dynamic ptr/arr
 */
int *fillArr (int *p, int SIZE)
{
    p = new int [SIZE];
    //loop to fill array
    for (int i = 0; i < SIZE; i++)
    {
        p[i] = i % 16;
    }
    return p;
}
/*
 * This function serves the purpose of outputting a ptr/array to the console
 * takes a loop and outputs every element.
 */
void outputArr (const int *p, int SIZE)
{
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(6) << p[i];
        count++;
        if (count == 8)
        {
            cout << endl;
            count = 0;
        }
    }
}
/*
 * This is a sort function utilizing "marks way" two loops going through the
 * elements and swapping them if one is less than the other. returns nothing
 */
void sortArr (int *p, int SIZE)
{
    int temp = 0;
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (p[j] < p[i])
            {     
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
}
/*
 * This function serves for getting the mode of a set of numbers. First, it
 * finds the me frequency, then it finds the modes within the elements, and
 * finally creates an array that sends the found # modes to it. returns a ptr
 * with modes in it.
 */
int *mode (int *p, int SIZE, int &SIZE2)
{
    int *modePtr;
    int maxFreq = 0;
    int temp = 0;
    //starting loop to cycle thru elements
    for (int i = 0; i < SIZE - 1; i++)
    {  //int to check for repeats
        int freq = 0;
        //checking repeats
        if (p[i] == p[i + 1])
        {
            temp = p[i];
            //loop to check rest of elements for repeats
            for (int j = i; j < SIZE; j++)
            { //if repeat is found add +1 to counter
                if (temp == p[j])
                {
                    freq++;
                }
            } //if a new high number of repeats is found will set to max Freq
            if (freq > maxFreq)
            {
                maxFreq = freq;
            }
        }
    }
    cout  << "\nThe max frequency is:   " << maxFreq << endl;
    int modeSize =0;
    int modeEle=0;
    int modeNum =0;
    //loop thru ptr
    if (maxFreq != 0)
    {
        modePtr = new int [modeSize];
        for (int i = 0; i < SIZE-1; i++)
        {
        //checking to see if element is equal to (element+maxFreq-index) which 
        //if it is then that would be a mode number in that list of elements
            if (p[i] == p[maxFreq -1 +i])
            {//counter for size of mode
            modeSize++;
            }      
        }        
    //cout << "this many times: " << modeSize << endl;
        
    //loop thru ptr
        for (int i = 0; i < SIZE-1; i++)
        {
        //checking to see if element is equal to (element+maxFreq-index) which 
        //if it is then that would be a mode number in that list of elements
            if (p[i] == p[maxFreq -1 +i])
            {
            //setting found number thats a mode to the element of a ptr
               int temp = p[i];
               modePtr[modeEle] = temp;
               modeEle++;
            }      
        }
    }
    else 
    {
        cout << "\nThere is no mode setting to -1!!!" << endl;
        modeSize++;
        modePtr = new int [modeSize];
        modePtr[0] = -1;
    }
    
    SIZE2 = modeSize;
    return modePtr;
}
/*
 * This function takes a list of numbers from an arry/ptr and then calculates
 * the mean of the list of numbers. returns the mean of the numbers
 */
float mean (int *p, int SIZE)
{
    float avg =0;
    float num = 0;
    //loop to go thru numbers
    for (int i=0; i < SIZE; i++)
    {   
        num = p[i];
        avg += num;
    }
    avg = avg/SIZE;
    return avg;
}
/*
 * This function finds the median of elements in a ptr and if the number of
 * elements is even it takes the two middle numbers and divides them, then
 * if odd elements just takes middle num. returns the median.
 */
float median (int *p, int SIZE)
{
    float median = 0;
    int even;
    even = SIZE % 2;
    if (even == 0)
    {
        int num1, num2;
        num1 = p[(SIZE/2)-1];
        num2 = p[(SIZE/2)+1];
        //cout << "NUM1: " <<num1<< " " << "NUM2: " << num2 << " " << endl;
        median = (num1 + num2)/2;
        //cout << "MEDIAN: " << median << " " << endl;
    }
    else 
    {
        int num = p[SIZE/2];
        //cout << "NUM: " << num << " " << endl;
        median = num;
        //cout << "MEDIAN: " << median << " " << endl;
    }
        return median;
}