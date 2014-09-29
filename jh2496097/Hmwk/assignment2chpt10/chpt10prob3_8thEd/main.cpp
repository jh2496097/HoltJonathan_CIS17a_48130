/* 
 * Jonathan Holt
 * C++ objects
 * HW 2
 * i certify this is my work
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>

using namespace std;

/*
 * 
 */
int words (char [], int );
int words (string, int );
bool isAlpha (char[], int);

int main(int argc, char** argv) {

    const int MAX = 87;
    char sentence[MAX];
    int wordCount =0;
    
    cout << "Please enter a sentence: " << endl;
    cin.getline(sentence, MAX);
    wordCount = words (sentence, MAX);
    cout << "The word count is : " << wordCount << "." << endl;
    
    return 0;
}
int words (char m[], int size)
{
    int counter =0 ;
    int length = strlen(m);
    for (int i = 0; i < length + 1; i++)
    {
        if (m[i] == ' ' )
        {   
            counter++;
        }
    }
    //counter + 1 to get the first word
    counter++;
    return counter;
}
bool isAlpha (char m[], int charSize)
{
    const int size =27;
    char alphabet[size] ="qwertyuioplkjhgfdsamnbvcxz";
    
    for (int i=0; i<charSize; i++)
    {
        for (int j=0; j < size; j++)
        {
            if (m[i] == alphabet[j])
            {
                return true;
            }
        }
    }
    return false;
}