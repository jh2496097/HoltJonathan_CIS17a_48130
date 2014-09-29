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
void setSize (float *ptr, int size);
void output (const float *ptr, int size);
void setDonations (float *ptr, int size);
void arrangeSet (float *ptr, int size);

int main(int argc, char** argv) {
    
    cout << "This program allocates donations to a dynamic array that " <<
            endl<< "the user must enter." << endl;
    char choice;
    int size = 0;
    float *donations = NULL;
    do
    {
        //setSize(donations, size);
        cout << "Enter the number of donations you wish to enter: " << endl;
        cin >> size;
        while (size < 1)
        {
            cout << "Please enter a number bigger than 0." << endl;
            cin >> size;
        }
        const int NUM_DONATE = size;
        //setting size of dynamic array according to user
        donations = new float [NUM_DONATE]; 
        //output (donations, size);
        setDonations (donations, NUM_DONATE);
        cout << "\nDONATIONS RECEIVED:" << endl;
        output (donations, NUM_DONATE);
        arrangeSet (donations, NUM_DONATE);
        cout << "\nDONATIONS SORTED:" << endl;
        output (donations, NUM_DONATE);
        
        delete [] donations;
        donations = NULL;
       
        cout << "Do you wish to quit press 'q' or press anything else to" <<
                endl << "to continue." << endl;
        cin >> choice;
    }while (choice != 'q');

    return 0;
}
/*
 * This function creates a dynamic array in which the user gets to decide 
 * on how big it is. Also does a user check to make sure user doesn't enter 
 * a negative number for size of dynamic ptr/array. 
 */
void setSize (float *ptr, int size)
{
    cout << "Enter the number of donations you wish to enter: " << endl;
    cin >> size;
    while (size < 1)
    {
        cout << "Please enter a number bigger than 0." << endl;
        cin >> size;
    }
    ptr = new float [size];
}
/*
 * This function displays the contents of a dynamic pointer it keeps the pointer
 * constant that way values are not change and returns nothing.
 */
void output (const float *ptr, int size)
{
    int space = 0;
    cout << endl << fixed << setprecision(2);
    for (int i =0; i < size; i++)
    {   
        cout << "$" << *(ptr + i) << "    " ;
        space++;
        if (space == 5)
        {
            space = 0;
            cout << endl;
        }
    }
    cout << endl;
}
void setDonations (float *ptr, int size)
{
    float donation =0;
    cout << "Please enter the donations. You entered that there was" << endl
            << size << " different donations." << endl;
    
    for (int i=0; i < size; i++)
    {
        cout << "Enter donation " << i + 1 << ": " << endl;
        cin >> donation;
        while (donation <= 0)
        {
            cout << "Enter a higher donation than 0. " << endl;
            cin >> donation;
        }
        *(ptr + i) = donation;
    }
}
/*
 * This function arranges the dynamic array/ptr to have values ranging from
 * least to greatest it utilizes the selection sort.'
 * returns nothing
 */
void arrangeSet (float *ptr, int size)
{
    int start = 0;
    int found = 0;
    float minValue;
    for (int start = 0; start < size -1; start++)
    {
        found = start;
        minValue = ptr[start];
        for (int j = start; j < size; j++)
        {
            if (ptr[j] < minValue)
            {
                minValue = ptr[j];
                found = j;
            }
        }
        ptr[found] = ptr[start];
        ptr[start] = minValue; 
    }
}