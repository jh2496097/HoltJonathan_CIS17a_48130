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
#include <string>

using namespace std;

/*
 * 
 */
void makeSpace (string &word);

int main(int argc, char** argv) {

    string sentence = "HeyHowAreYaDoing";
    string sentence1;
    cout << sentence << endl;
        
    makeSpace (sentence); 
    cout << sentence << endl;
    
    cout << "Enter a sentence with no spaces and words separated by capital"
            << endl << "letters." << endl;
    cin >> sentence1;
    makeSpace (sentence1); 
    cout << sentence1 << endl;
    
    return 0;
}
/*
 * this function goes through a string and starts from position 1 not 0 to keep
 * first word changing. After that goes through rest of string finding an 
 * uppercase letter and inserting a space inbetween the words then lowercases 
 * the next character. returns nothing
 */
void makeSpace (string &word)
{
    int length = word.size();
    for (int i =1; i < length; i++)
    {
        if (isupper(word[i]))
        {
            word.insert(i, " ");
            word[i+1] = tolower(word[i+1]);
        }
    }
}
