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

string reOrder (string word);
int words (string words);
void setWords (string *arry, string word);
void pigChng (string *arry, int size);

int main(int argc, char** argv) {

    string sentence;
    string newWord;
    
    cout << "This program changes sentences into Pig Latin! " << endl;
    cout << "Enter a sentence to convert: " << endl;
    getline (cin, sentence);
    const int SIZE = words (sentence);
    //creating an array to work with words individually
    string arry [SIZE];
    setWords (arry, sentence);
    //pigChng (arry, SIZE);
    
    for (int i = 0; i < SIZE; i++)
    {
        cout << arry[i] << " " ;
    }
    /*newWord = reOrder (sentence);
    cout << newWord << endl;
    newWord = pigLatin (newWord);
    cout << newWord << endl;*/
    
    cout << endl;
    return 0;
}
/*
 * This function takes a word then rearranges that word with the first letter
 * being attached to the back and then adding "ay" to the word. It then 
 * returns the new reconfigured word.
 */
string reOrder (string word)
{
    string newWord = word;
    int length = word.size();
    char temp;
    temp = newWord[0];
    newWord[0] = newWord[length-1] ;
    newWord[length-1] = temp;
    newWord = newWord + "ay";
    return newWord;
}
/*
 * This function takes the array with words in it and calls the function reorder
 * to change the words to piglatin. Goes thru each word in the array
 * returns nothing
 */
void pigChng (string *arry, int size)
{
    string changeWord;
    for (int i = 0; i < size; i++)
    {
        changeWord = arry[i];
        changeWord = reOrder (arry[i]);
        arry[i] = changeWord;
    }
}
/*
 * Takes a string and adds each word from the string to the array individually
 * looks for a space or null terminator to find the actual word then send it
 * to an array to be stored. returns nothing
 * 
 */
void setWords (string *arry, string word)
{
    int count = 0;
    int position = 0;
    string newWord;
    int length = word.size();
    
    for (int i =0; i < length+1; i++)
    {     
        newWord += word[i];
        if (word[i] == ' ' || word[i] == '\0')
        {
            arry[position] = newWord;
            newWord = "";
            position++;
        }
    }
    //need a delete []
    
}
/*
 * This function goes thru a string and counts the number of words in the string
 * if a space is located then a word is present has a counter that adds up
 * returns the counter
 */
int words (string words)
{
    int counter =0 ;
    int length = words.size();
    for (int i = 0; i < length + 1; i++)
    {
        if (words[i] == ' ' )
        {   
            counter++;
        }
    }
    //counter + 1 to get the first or last word
    counter++;
    return counter;
}