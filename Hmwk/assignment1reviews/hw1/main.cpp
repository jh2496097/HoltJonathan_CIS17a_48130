/* 
 * Jonathan Holt
 * C++ objects
 * HW 1
 * i certify this is my work
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;


void createSpace();
void outputIntro(char &choice);

void chpt3_num12();

void chpt3num13 ();

void chpt4num10();

void chpt5num11();

float celsius (int number);
void tableFtoC();
void chpt6num7CtoF();

const int MONTH = 3;
const int DAY = 30;
void outputArray(const char chart [][DAY], int row);
void assignArray(char chart [][DAY], int row, ifstream &txt);
void weatherDayCounter (const char chart [][DAY], int row);
void chpt7num6();

const int SIZE = 20;
void outputArray (string array[], int size);
void arrangeArray(string array[], int size);
void bubbleArrange( string array[], int size);
string binarySearch(string array[], int size, string word);
void chpt8num7 ();
int main(int argc, char** argv) {

    char choice;
    do
    {
        //cin.ignore(1024, '\n'); used for getline but changed
        outputIntro(choice);
   
                switch (choice)
                {
                case 'a': 
                    createSpace();
                    cout << "This is homework assignment 1." << endl;
                    chpt3_num12();
                    createSpace();
        
                break;
                case 'b': 
                    createSpace();
                    cout << "This is homework assignment 2." << endl;
                    chpt3num13 ();
                    createSpace();
        
                break;
                case 'c': 
                    createSpace();
                    cout << "This is homework assignment 3." << endl;
                    chpt4num10();
                    createSpace();
        
                break;
                case 'd': 
                    createSpace();
                    cout << "This is homework assignment 4." << endl;
                    chpt5num11();
                    createSpace();
        
                break;
                case 'e': 
                    createSpace();
                    cout << "This is homework assignment 5." << endl;
                    chpt6num7CtoF();
                    createSpace();
        
                break;
                case 'f': 
                    createSpace();
                    cout << "This is homework assignment 6." << endl;
                    chpt7num6();
                    createSpace();
        
                break;
                case 'g': 
                    //cin.ignore(1024, '\n');
                    createSpace();
                    cout << "This is homework assignment 7." << endl;
                    chpt8num7 ();
                    createSpace();
        
                break;
                case 'h':
                    createSpace();
                    cout << "Quitting!" << endl;
                        
                    //cin.ignore(1024, '\n');

        }
    }while (choice != 'h');

    return 0;
}
/*
 * Simple function that gives a user a menu of the start of a loop
 * it is part of a choice list.
 * returns nothing
 */
void outputIntro(char &choice)
{
    cout << "This is your main page." << endl;
    cout << "There are currently 7 programs to choose from please" << endl;
    cout << "enter a letter from a to g or h to quit." << endl;
    cout << "a. 3.12"<< endl << "b. 3.13" << endl << "c. 4.10" << endl <<
            "d. 5.11" << endl << "e. 6.7" << endl << "f. 7.6" << endl <<
            "g. 8.7" << endl << "h. quit" << endl;
    cin >> choice;
    while (choice != 'a' && choice != 'b' && choice != 'c'&&choice != 'd' &&
            choice != 'e' &&choice != 'f' &&choice != 'g' && choice != 'h')
    {
        cout << " Please enter a correct letter." << endl;
        cin >> choice;
    }
}
/*
 * function that creates space
 * returns nothing
 */
void createSpace()
{
    for (int i = 0; i < 15; i++)
    {
        cout << endl;
    }
}
/*
 * This program converts Celsius to Fahrenheit and asks user for an integer of 
 * celsius and casts it into a float to convert into a float variable of 
 * fahrenheit.
 * returns nothing
 */
void chpt3_num12()
{
    cout << "This program converts Celsius temperatures to Fahrenheit " << endl
            << "temperatures." << endl;
    int numCelsius;
    float numFahrenheit;
    char choice;
    do
    {
        cout << "Enter a number for Celsius" << endl;
        cin >> numCelsius;
        
        numFahrenheit = ((static_cast <float>(numCelsius) * 9)/ 5) + 32;
        cout << "The conversion of Celsius: " << numCelsius << " to "
                "Fahrenheit is: " << numFahrenheit << endl << endl << endl;
        cout << "Want to enter a new number or quit press 'q' to quit" <<endl;
        cin >> choice;
    }while(choice != 'q');
}            
/*
 * This function returns nothing but takes in an amount of american dollars
 * and thru the user then converts it to yen and euros uses data type float.
 */
void chpt3num13 ()
{
    float dollars;
    const float YEN_PER_DOLLAR = 104.04;
    const float EUROS_PER_DOLLAR = 0.76;
    char choice;
    cout << "This program converts US dollars to the different amounts" << endl
            << "in Japanese yen and euros." << endl;
    do
    {
        float yen;
        float euros;
     
        cout << "Enter an amount in US dollars: " << endl;
        cin >> dollars;
        cout << "You entered: $" << setprecision(2) << fixed << dollars << endl;
        
        yen = dollars * YEN_PER_DOLLAR;
        euros = dollars * EUROS_PER_DOLLAR;
        
        cout << "From US dollars: " << dollars << " to yen: " << yen << "yen" 
                << " to euros: " << euros << "euros" << endl << endl << endl;
        cout << "Want to enter a new number or quit press 'q' to quit" <<endl;
        cin >> choice;
        cout << endl;
    }while (choice != 'q');
}
/*
 * This function calculates leap years and tells how many days are in the month
 * during that year and displays the days. Takes into account the month of 
 * febuary and if the year is a leap year will say that month has 29 days or 
 * else 28 days. Then every other month alternates 30 to 31.
 * returns nothing
 */
void chpt4num10()
{
    cout << "This program asks the user for a month and year and tells " << endl
            << "the user how many days are in that month and year." << endl;
    int month;
    int year;
    int days;
    char choice;
    
    do
    {
        bool leapYear = false;
        cout << "Enter a month (1-12): " << endl;
        cin >> month;
        while (!(month >= 1 && month <= 12))
        {
            cout << "Please enter a correct month." << endl;
            cin >> month;
        }
        cout << endl << "Enter a year: " << endl;
        cin >> year;
        while (year < 0)
        {
            cout << "Please enter a correct year above 0." << endl;
            cin >> year;
        }            
                      //the && takes precedence over the || 
        //if (year % 100 == 0 && year % 400 == 0 || year % 4 == 0)
        //so this formula is correct
        if (year % 4 ==0 && year % 100 != 0 || year % 400 == 0)
        {
            //cout << "this is a leap year" << year << endl;
            leapYear = true;
        }
        if (leapYear == true && month == 2)
        {
            days = 29;
            cout << days << " days in month " << month << " and year " << year 
                    << endl << endl;
        }
        else if (month == 2)
        {
            days = 28;
            cout << days << " days in month " << month << " and year " << year 
                    << endl << endl;
        }
        else if (month % 2 == 0 && month != 2)
        {
            days = 30;
            cout << days << " days in month " << month << " and year " << year 
                    << endl << endl;
        }
        else
        {
            days = 31;
            cout << days << " days in month " << month << " and year " << year 
                    << endl << endl;
        }
        
        cout << "To quit press 'q' or enter anything else to run program" <<
                endl<< "again." << endl;
        cin >> choice;
    }while(choice != 'q');
}
/*
 * This function takes in multiple values to calculate a given population
 * it takes into consideration input error as well and then outputs them to
 * the console per each day
 * returns nothing
 */
void chpt5num11()
{
    cout << "This program predicts the size of a population of organisms." <<
         endl;
    int population;
    float popIncrease;
    int days;
    float newPop;
    char choice;
    do
    {
        cout << "Enter the starting population for the organisms: " << endl;
        cin >> population;
        while (population <= 1)
        {
                cout << "Enter a population that is greater than 1: " << endl;
                cin >> population;
        }
        cout << "Enter their average daily population increase as a %(percent):" 
                << endl;
        cin >> popIncrease;
        while (popIncrease < 0)
        {
                cout << "Enter a percent greater or equal to 0: " << endl;
                cin >> popIncrease;
        }
        cout << "Enter the amount of days the organism will multiply: " << endl;
        cin >> days;
        while(days <= 0)
        {
                cout << "Enter the days greater than 0:" << endl;
                cin >> days;           
        }
    //setting population for day 1
        newPop = population;
    //changing percent into a number
        popIncrease = popIncrease * 0.01 ;
    //cout << popIncrease << endl;
    //to display population each day
        for (int i = 1; i <= days; i++)
        {       
                cout << "Population on day " << i << ": " << 
                        static_cast<int>(newPop)<< endl;
                newPop = newPop * popIncrease + newPop;
        }
        cout << "Do wish to quit press 'q' or press any other key to run " << 
                endl << "program again." << endl;
        cin >> choice;
    }
    while(choice != 'q');
}
/*
 * This function converts a fahrenheit number to celsius number
 * returns the celsius number
 */
float celsius (int number)
{
    return  (number - 32)*5/9.0 ;
}
/*
 * This function is a table that is used to show a table between 0 to 20 in
 * Fahrenheit to celsius
 */
void tableFtoC()
{
    cout << "Here is a table showing the conversion of 0 to 20 Fahrenheit"
            << endl << "to Celsius." << endl;
    cout  << "Fahrenheit" << "  to  " << "Celsius" << endl;
    int fahrenheit;
    float celsiusNum;
    for (int i = 0; i < 21 ; i++)
    {
        celsiusNum = celsius (i);
        cout << i  << setw(20) << celsiusNum << endl;
    }
}
/*
 * This function takes fahrenheit temperature and converts it to celsius
 * it also outputs a table 
 * returns nothing
 */
void chpt6num7CtoF()
{
    cout << "This program converts Fahrenheit to Celsius and also outputs a " <<
            endl << "table of temperatures from 0 to 20. " << endl;
    char choice;
    int fahrenheit;
    float celsiusNum;
    do
    {
        cout << "Enter a Fahrenheit temperature and I will convert to " 
                "Celsius." << endl;
        cin >> fahrenheit;
        celsiusNum = celsius (fahrenheit);
        
        cout << fixed << setprecision(2) << "The number converted to "
                "Celsius is: " << celsiusNum << endl;
        //calling function table
        tableFtoC();
        
        //input choice
        cout << "Do you wish to quit press 'q' or anything else to continue" 
                <<endl;
        cin >> choice;
    }while(choice != 'q');
}
/*
 * This function simply outputs a 2D array with a description of the rows
 * next to it.
 * returns nothing
 */
void outputArray(const char chart [][DAY], int row)
{
    int count1=1;
    int count2=1;

    cout << "Days:1-30" << endl;

    for (int i = 0; i < row; i++)
    {
        
        for (int j =0; j < DAY; j++)
        {
            cout << chart[i][j] << " " ;
        }
        if (count1 ==1)
        {
                cout << "June " ;
        }
        if (count1 ==2)
        {
                cout << "July " ;
        }
        if (count1 ==3)
        {
                cout << "August " ;
        }
        count1++;
        cout << endl;
    }
}
/*
 * Assign values of char value to a 2D array. Takes the information from a 
 * file that is arranged according to user. Then stores those values accordingly
 * into a 2D array.
 * returns nothing
 */
void assignArray(char chart [][DAY], int row, ifstream &txt)
{
    char letter;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < DAY; j++)
        {
            txt >> letter;
            cout << " " ;
            chart[i][j] = letter;
            //chart[i][j] = 'T';
        }
    }
}
/*
 * Calculates the amount of rainy days, sunny days, and cloudy days, in a 2D
 * array basically searches the array for whatever each day is and adds a plus
 * counter to total up the amount of days
 * Then outputs that information
 * returns nothing
 */
void weatherDayCounter (const char chart [][DAY], int row)
{
    int sunnyCount=0, cloudyCount=0, rainyCount=0;
    int juneRain = 0, julyRain=0, augustRain=0;
    for (int i=0; i < 1; i++)
    {
        for( int j = 0; j < DAY; j++)
        {
            if (chart[i][j]=='S')
            {
                sunnyCount++;
            }
            if (chart[i][j]=='C')
            {
                cloudyCount++;
            }
            if (chart[i][j]=='R')
            {
                rainyCount++;
                juneRain++;
            }
        }
    }
    cout << endl<< "In June: " << endl;
    cout << "There were a total of " << sunnyCount << " sunny days." << endl;
    cout << "There were a total of " << cloudyCount << " cloudy days." << endl;
    cout << "There were a total of " << rainyCount << " rainy days." << endl;
    
    sunnyCount=0, cloudyCount=0, rainyCount=0;
    for (int i=1; i < 2; i++)
    {
        for( int j = 0; j < DAY; j++)
        {
            if (chart[i][j]=='S')
            {
                sunnyCount++;
            }
            if (chart[i][j]=='C')
            {
                cloudyCount++;
            }
            if (chart[i][j]=='R')
            {
                rainyCount++;
                julyRain++;
            }
        }
    }
    cout << endl<< "In July: " << endl;
    cout << "There were a total of " << sunnyCount << " sunny days." << endl;
    cout << "There were a total of " << cloudyCount << " cloudy days." << endl;
    cout << "There were a total of " << rainyCount << " rainy days." << endl;
    
    sunnyCount=0, cloudyCount=0, rainyCount=0;
    for (int i=2; i < 3; i++)
    {
        for( int j = 0; j < DAY; j++)
        {
            if (chart[i][j]=='S')
            {
                sunnyCount++;
            }
            if (chart[i][j]=='C')
            {
                cloudyCount++;
            }
            if (chart[i][j]=='R')
            {
                rainyCount++;
                augustRain++;
            }
        }
    }
    cout << endl<< "In Auguest: " << endl;
    cout << "There were a total of " << sunnyCount << " sunny days." << endl;
    cout << "There were a total of " << cloudyCount << " cloudy days." << endl;
    cout << "There were a total of " << rainyCount << " rainy days." << endl;
    
    cout << "And the most rainy month was: " << endl;
    if (juneRain > julyRain && juneRain > augustRain)
    {
        cout << "June!!!!!" << endl;
    }
    else if (julyRain > juneRain && julyRain > augustRain)
    {
        cout << "July!!!!!" << endl;
    }
    else if (augustRain > julyRain && augustRain > juneRain)
    {
        cout << "August!!!!!" << endl;
    }
    else if (augustRain == julyRain && augustRain == juneRain)
    {
        cout << "All three months were equally rainy." << endl;
    }
    else
        cout << "There was no specifically rainy month." << endl;
    
    cout << endl << endl;
}
/*
 * this function asks user to open a file that then checks to see if it exists
 * or not. If it does function continues to run if it doesnt function tells user
 * to create the file then closes
 * returns nothing
 */
void chpt7num6()
{
    cout << "This program takes weather data from a file and stores it" <<
            endl << "into an array 3 x 30." << endl << "For months June, "
            "July, August and taking only 30 days of each" << endl << "month." 
            << endl;
    
    char choice;
    char weatherRecord[MONTH][DAY];
    ifstream infile;

    do
    {
        infile.open("RainOrShine.txt");
        if (infile.fail())
        {
            cout << "Error opening the file closing program." << endl;
            cout << "Create the file." << endl;
        }
        else
        {
            //assisgns the weather days to the array
            assignArray(weatherRecord, MONTH, infile);
            //outputs
            outputArray(weatherRecord, MONTH);
            //call weather day counter function
            weatherDayCounter (weatherRecord, MONTH);
        }      
        infile.close();
        
        
        cout << "Do you want to quit press 'q' or press anything else to" 
                << endl << "run again." << endl;
        cin >> choice;
    }while(choice != 'q' /*|| infile.fail()*/);
}
/*
 * outputs the string array
 * returns nothing
 */        
void outputArray (string array[], int size)
{
    for (int i =0; i < size; i++)
    {
        cout << array[i] << "    " << endl;
    }
    cout << endl << endl;
}
/*
 * The function takes a string array and orders it alphabetically
 * ****NOT WORKING***** skip
 */
void arrangeArray(string array[], int size)
{
    int start=0, minIndex;
    string minValue;
    //location of minimum
    for(int i = 0; i < size -1; i++)
    {
        minIndex = start;
        minValue = array[start];
        //find the minimum int loc =0
        for (int i = start+1; i < size; i++)
        {
            if(array[i] > minValue)
            {
                minValue =array[i];
                minIndex =i;
            }
        }
        array[minIndex]=array[start];
        array[start]=minValue;
    }
}
/*
 * this function serves the purpose of sorting a string array in the way of 
 * bubble sort. The bubble sort goes through an index and basically swaps the 
 * values inside the index if the value is lower than the other.
 * returns nothing
 */
void bubbleArrange(string array[], int size)
{
    bool swap;
    string temp;
    do
    {
        swap = false;
        for (int i = 0; i < size -1; i++)
        {
            if(array[i] >array[i+1])
            {
                temp = array[i];
                array[i]=array[i+1];
                array[i+1] = temp;
                swap = true;
            }
        }
    }while (swap);
}
/*
 * This function takes a binary search thru a string an array and takes a word
 * and tries to find it. The word is taken from the user and the binary search
 * function then searches the the array to find the word. If word is not found
 * the function displays name not found other it states the name.
 * returns the name or 'name not found'
 */
string binarySearch(string array[], int size, string word)
{
    int middle, first= 0, last= size-1;
    string name = "Name not";
    string temp;
    bool found = false;
    while (!found && first <= last)
    {
        middle = (first + last)/2;
        temp = array[middle];
        if (temp == word)
        {
            found = true;
            name = temp;
        }
        else if (temp > word)
        {
            last = middle - 1;
        }
        else
            first = middle + 1;
    }
    //cout << endl << "*****"  << name << "*******" << endl << endl;
    return name;
}
/*
 * This program has a list of names that is manually inputted into an array. The
 * purpose of this function is to run continuously till user wants it to end. 
 * takes a user inputed name and searches the array for it.
 * returns nothing. 
 * 
 */
void chpt8num7 ()
{
    cout << "This program is a binary search that looks at an array of strings"
            << endl ;
    char choice = ' ';
    string searchWord;
    string strArray[SIZE] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                             "Griffin, Jim","Stamey, Marty","Rose, Geri",
                             "Taylor, Terri","Johnson, Jill", "Allison, Jeff",
                             "Looney, Joe","Wolfe, Bill","James, Jean",
                             "Weaver, Jim","Pore, Bob", "Rutherford, Greg",
                             "Javens, Renee","Harrison, Rose","Setzer, Cathy",
                             "Pike, Gordon","Holland, Beth"};
    do
    {   
        string fname, lname;
        /*cout << "Enter a word to be searched through the string array." << endl;
        getline(cin, searchWord);  
        cout << endl;*/
        //NEED  cin.ignore(1024, '\n'); for getline to work
        cout << "Enter the first name of the person to be searched : " ;
        cin >> fname;
        cout << "Enter the last name of the person: " ;
        cin >> lname;
        searchWord = lname + ", " + fname;
        
        //outputArray (strArray, SIZE);
        /*arrangeArray(strArray, SIZE);
        outputArray (strArray, SIZE);*/
        //cin.clear();
        //cin.ignore(100, '\n'); 
        cout << "The names in alpabetical order: " << endl;
        bubbleArrange(strArray, SIZE);
        outputArray (strArray, SIZE);
        
        
        
        string searchName = binarySearch(strArray, SIZE, searchWord);
        cout << "The name you entered: " << searchName << " found." << 
                endl << endl;
        
        cout << "Do you want to quit press 'q' or press anything else to"
                <<endl << "try again." << endl;
        cin >> choice;
       
    }
   while(choice != 'q');
}