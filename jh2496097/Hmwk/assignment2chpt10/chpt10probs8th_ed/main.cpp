/*
 * Jonathan Holt
 * C++ objects
 * i certify this is my work
 * Created on October 1, 2014, 3:27 PM
 * 
 * Assignment 2
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

/*
 * 
 */
//prob3
int words (char m[], int size);
void prob3 ();
//prob12
void prob12();
//prob14
void makeSpace (string &word);
void prob14();
//prob15
void prob15 ();
//prob16
string reOrder (string word);
void pigChng (string *arry, int size);
void setWords (string *arry, string word);
int words (string words);
void prob16();

void createspace();

int main(int argc, char** argv) {
    //choice to end do while
    char choice;
    do
    {
        //choice for problems
        char probChoice;
        
        cout << "This is a list of chapter 10 problems." << endl;
        cout << "Choose between the numbers 1 to 5" << endl;
        cout << "1. Chptr10 number 3 word counter" << endl;
        cout << "2. Chptr10 number 12 password" << endl;
        cout << "3. Chptr10 number 14 word separator" << endl;
        cout << "4. Chptr10 number 15 file analysis" << endl;
        cout << "5. Chptr10 number 16 pig latin" << endl;
        cin >> probChoice;
        
        switch (probChoice)
                {
                case '1': 
                    createspace();
                    prob3 ();
                break;
                case '2': 
                    createspace();
                    prob12();
                break;
                case '3': 
                    createspace();
                    prob14();
                break;
                case '4': 
                    createspace();
                    prob15 ();
                break;
                case '5': 
                    createspace();
                    prob16();
                break;
            
            default: cout << "You entered a wrong choice\n";
            createspace();
        }
        createspace();
        cout << "Do you wish to pick another program enter anything else " << 
                endl << "besides 'q' or 'Q': " << endl;
        cin >> choice;
    }while(toupper(choice) != 'Q');
    
    
    return 0;
}
/*
 * creates space for easier reading
 */
void createspace()
{
    for (int i=0 ; i < 4; i++)
    {
        cout << endl;
    }
}
/*
 * This program looks at a character array and finds a blank spot ' ' then
 * checks the very next index for a letter and if there is a ' ' + a letter
 * then word count goes up
 */
int words (char m[], int size)
{
    int counter =0 ;
    int length = strlen(m);
    for (int i = 0; i < length + 1; i++)
    {
        if (m[i] == ' ' && isalpha(m[i+1]))
        {   
            counter++;
        }
    }
    //counter + 1 to get the first word
    counter++;
    return counter;
}
/*
 * A stub in place of a main function.
 */
void prob3 ()
{
    const int MAX = 87;
    char sentence[MAX];
    int wordCount =0;
    
    cout << "Please enter a sentence: " << endl;
    cin.ignore();
    cin.getline(sentence, MAX);
    wordCount = words (sentence, MAX);
    cout << "The word count is : " << wordCount << "." << endl;
}
/*
 * program used to run problem 12 from the gaddis book uses bools to do checks
 */
void prob12()
{
    string password;
    bool digit;
    bool upper ;
    bool lower ;
    bool num ;
    bool works = false;
    do
    {
        digit = false;
        upper = false ;
        lower = false;
        num = false;
        cout << "Enter a password. Needs to be at least 6 characters, it needs"
                << endl << "one uppercase and one lowercase letter, and 1 "
                "digit." <<  endl;   
        cin >> password;
        int length = password.size();
    
        if(length < 6)//checking size
        {
            cout << "Password is too short!!" << endl;
        }
        else //setting to true if bigger than 6
            num = true;
    
        for (int i =0; i < length; i ++)
        {
            if(isdigit(password[i]))//checking for digits
            {
                digit = true;
            }
            if(isupper(password[i]))//checking for uppercase
            {
                upper = true;
            }
            if(islower(password[i]))//checking for lowercase
            {
            lower = true;
            }
        }
        if(digit == false)
        {
            cout << "Password needs a number!!" << endl;
        }
        if(upper == false)
        {
            cout << "Password needs an uppercase letter!!" << endl;
        }
        if(lower == false)
        {
            cout << "Password needs a lowercase letter!!" << endl;
        }
        //check to make sure all are satisfied
        if (digit== true && upper== true && lower== true && num== true)
        {
            works = true;
        }

    }while(works != true);
    cout << "Password works!!!" << endl;
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
/*
 * stup for prob 14 gaddis 8thed
 */
void prob14()
{
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
}
/*
 * this program opens a file then proceeds to go through the file keeping a 
 * track of numbers lower and higher case alphabets the outputs them.
 */
void prob15 ()
{
    ifstream infile;
    infile.open("text.txt");
    char spot;
    int upCount =0;
    int lowCount =0;
    int numCount =0;
    if (!infile)
    {
        cout << "File doesn't exist!" << endl;
    }
    else
        cout << "This is what is in the file:" << endl;
    while (infile >> spot)
    {
        cout << spot ;
        if(isupper(spot))
        {
            upCount++;
        }
        if(islower(spot))
        {
            lowCount++;
        }
        if(isdigit(spot))
        {
            numCount++;
        }
    }
    cout << "\n\nThere is currently " << lowCount << " lowercase letters." << 
            endl;
    cout << "There is currently " << upCount << " uppercase letters." << endl;
    cout << "There is currently " << numCount << " numbers." << endl;
    cout << endl;
    
    infile.close();
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
    
    for (int i = 0; i < length+1; i++)
    {
        if(isalpha(word[i]))
        {
            newWord += word[i];
        }
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
void prob16()
{
    string sentence;
    string newWord;
    
    cout << "This program changes sentences into Pig Latin! " << endl;
    cout << "Enter a sentence to convert: " << endl;
    cin.ignore();
    getline (cin, sentence);
    const int SIZE = words (sentence);
    //creating an array to work with words individually
    string arry [SIZE];
    setWords (arry, sentence);
    pigChng (arry, SIZE);
    
    for (int i = 0; i < SIZE; i++)
    {
        cout << arry[i] << " " ;
    }
    //IGNORE
    /*newWord = reOrder (sentence);
    cout << newWord << endl;
    newWord = pigLatin (newWord);
    cout << newWord << endl;*/
    
    cout << endl;
}