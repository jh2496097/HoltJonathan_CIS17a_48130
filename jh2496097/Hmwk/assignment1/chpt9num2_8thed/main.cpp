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
void showScores (const int *ptr, int size);
void getScores (int *ptr, int size);
float avScore (int *ptr, int size);
void sortScores(int *ptr, int size);

int main(int argc, char** argv) {
    
    int *scores = NULL;
    int testScores = 0;
    float avg = 0;
    cout << "This program asks the user to enter a number to represent"
            << endl << "the number of tests the user wishes to input" << endl
            << "Then is makes a dynamic array of that number. Then asks the "
            << endl << "user to proceed entering test scores and will take" 
            << endl << "the average of inputted scores." << endl << endl;
    char choice;
    do
    {
        cout << "Enter a number to represent the amount of test scores" << endl 
            << "you wish to enter: " << endl;
        cin >> testScores;
    //input validation
        while (testScores < 1)
        {
            cout << "Please enter a number that is greater than 0 for" << endl
                << "the amount of test scores: " << endl;
            cin >> testScores;
        }
            const int NUMSCORES = testScores;
    //dynamic pointer or array with user input for size.
            scores = new int [NUMSCORES];
    
           getScores (scores, testScores);
    //showTests (scores, testScores);
           avg = avScore (scores, testScores);
           sortScores(scores, testScores);
           showScores (scores, testScores);
    
           cout << fixed << setprecision(1) << "The average of the test scores is " << 
            ": " << avg <<endl << endl;
           delete [] scores;
           scores = NULL;
           
           cout << "Do you wish to quit press 'q' or anything else to " << endl
                   << "restart the program. " << endl;
           cin >> choice;
    
     } while (choice != 'q');

    return 0;
}
/*
 * This function serves the purpose of entering scores into a pointer to be
 * stored. Checks for scores entered only 0 and above. It requires parameters
 * containing arguments of a pointer and the size of the dynamically created 
 * pointer.
 * returns nothing
 */
void getScores (int *ptr, int size)
{
    int score;
    cout << "Enter your test scores, you may enter " << size << " scores.\n";
    for (int i =0; i < size; i++)
    {
        cout << "Enter test score " << i + 1 << ": " ;
        cin >> score;
        while (score < 0)
        {
            cout << "Enter a number greater than -1 for a score: " << endl;
            cin >> score;
        }
        *(ptr + i) = score;
    }
}
/*
 * This function displays the contents of a pointer array.
 * returns nothing
 */
void showScores (const int *ptr, int size)
{
    cout << "\nThe scores entered are: " << endl; 
    for (int i = 0; i < size; i++)
    {
        cout << *(ptr + i)  << "   " << endl; 
    }
}
/*
 * This function takes the dynamic array and sums the scores and gives an 
 * average of the scores. parameters are a pointer array and the size of it.
 * returns the average.
 */
float avScore (int *ptr, int size)
{
    float total = 0;
    for (int i = 0; i < size; i++)
    {
        total += *(ptr+i);
    }
    total = total / size;
    return total;
}
/*
 * This function serves as a sorting function for a pointer array. Takes in 
 * the values and sorts them.
 * returns nothing
 */
void sortScores(int *ptr, int size)
{
    int startSort= 0;
    int minIndex=0;
    int minEle=0;
    for (int i = 0; i < size -1; i++)
    {
        startSort = i;
        minIndex = startSort;
        minEle = ptr[i];
        for (int j = startSort +1; j < size; j++)
        {
            if (ptr[j] < minEle)
            {
                minEle = ptr[j];
                minIndex = j;
            }
        }
        ptr[minIndex] = ptr[startSort];
        ptr[startSort] = minEle;
    }
}