/* 
 * Jonathan Holt
 * C++ objects
 * assignment 3
 * i certify this is my work
 * Created on October 18, 2014, 4:18 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

struct Speakers{
    string name;
    string teleNum;
    string topic;
    float fee;
};
struct SoccerTeam{
    string name;
    int number;
    int scores;
};
struct WeatherStats{
    int totRain;
    float highTemp;
    float lowTemp;
    float temp;
};
struct MovieData1
{
    string title;
    string director;
    int year;
    int runTime;
};
struct MovieData
{
    string title;
    string director;
    int year;
    int runTime;
    float revenue;
    float cost;
};
struct SodaMachine{
    string soda;
    float cost;
    int numLeft;
};
//prob13
const int SODAS = 5;
void inputData1(SodaMachine *list);
void output1 (SodaMachine *list);
void prob13();
//prob1
void output3 (MovieData1 m);
void prob1();
//prob2
MovieData getInfo ();
void output2 (MovieData m);
void prob2();
//prob4
void prob4();
//prob6
const int NUMPLYRS = 6;
void outputData (SoccerTeam m);
void prob6();

//prob9
const int NUM = 10;
void menu (char &);
void createspace();
void prob9();
//prob 10
void searchFor (Speakers *m);
void prob10();
int main(int argc, char** argv) {

    char numChoice;
    char choice;
    do
    {
    cout <<"Problems for chapter 11 in Gaddis book 8th edition. Strucures!" <<
            endl;
    cout << "7 Problems all should be working fine except 1 doesnt work" << 
            endl<<"completely. Enter a number as shown below: " << endl;
    cout << "1. Problem 1 Movie Data." << endl;
    cout << "2. Problem 2 Movie Data w/ Profit." << endl;
    cout << "3. Problem 4 Weather." << endl;
    cout << "4. Problem 6 Soccer Team." << endl;
    cout << "5. Problem 9 Speakers." << endl;
    cout << "6. Problem 10 Speakers (cont) not working fully." << endl;
    cout << "7. Problem 13 Soda Machine." << endl;
    cin >> numChoice;
    
        switch (numChoice){
        case '1':
            cin.ignore();
            createspace();
            prob1();
            break;
        case '2':
            cin.ignore();
            createspace();
            prob2();
            break;
        case '3':
            createspace();
            prob4();
            break;
        case '4':
            cin.ignore();
            createspace();
            prob6();
            break;
        case '5':
            createspace();
            prob9();
            break;
        case '6':
            createspace();
            prob10();
            break;
        case '7':
            createspace();
            prob13();
            break;
        default: cout << "Entered a wrong number!!!" << endl;
        createspace();
        }
    createspace();    
    cout <<"Do you wish to quit press 'q' or anything else to continue." 
                << endl;
    cin >> choice;
    
    }while(toupper(choice) != 'Q');
    return 0;
}
/*
 * creates space for easier reading
 */
void createspace()
{
    for (int i=0 ; i < 3; i++)
    {
        cout << endl;
    }
}
/*
 * Function that is utilized as the table for menu driven program.
 * returns nothing
 */
void menu (char &c)
{
    cout << "Enter the corresponding actions."  << endl;
    cout << "Enter 1, 2, 3, 4." <<endl;
    cout << "1. To add a speaker." << endl;
    cout << "2. Output a speakers information." << endl;
    cout << "3. To change contents of a speaker." << endl;
    cout << "4. To quit" << endl;
    cin >> c;
}
void menu2 (char &c)
{
    cout << "Enter the corresponding actions."  << endl;
    cout << "Enter 1, 2, 3, 4, 5." <<endl;
    cout << "1. To add a speaker." << endl;
    cout << "2. Output a speakers information." << endl;
    cout << "3. To change contents of a speaker." << endl;
    cout << "4. To search for topic." << endl;
    cout << "5. To quit" << endl;
    cin >> c;
}
void prob9(){
    Speakers present[NUM];
    int numSpeaker = 0;
    cout << "This program lets the user enter data for a speaker at a bureau." 
            << endl << "User is then prompted with menu driven program to do"
            " as they wish." << endl;
    cout << "MAX speakers allowed to be inputted is 9." << endl;
    cout << "Program will terminate if another is attempted to be added." << 
            endl;
    char choice;
    //int num=0;
    do{
        char probChoice;
        int num=0;
        menu (probChoice);
        
        switch(probChoice)
        {
            case '1':
                cin.ignore();
                cout << "Enter name of speaker: " ;
                getline (cin, present[numSpeaker].name);
                cout << "Enter speaker's telephone number: " ;
                getline (cin, present[numSpeaker].teleNum);
                cout << "Enter the speakers topic: " ;
                getline (cin, present[numSpeaker].topic);
                cout << "Enter the fees speaker requires: " ;
                cin >> present[numSpeaker].fee;
                while (present[numSpeaker].fee < 0){
                cout << "Enter fees above 0 non negative." << endl;
                cin >> present[numSpeaker].fee;     
                }
                cout << endl;
                //cin.ignore();
                numSpeaker++;
                createspace();
                break;
            case '2':
                cout << "You currently have " << numSpeaker << " speaker(s)"<<
                " to choose from." << endl;
                cout << "Which speaker would you like to output." << endl;
                cin >> num;
                while (num < 1 || num > numSpeaker)
                {
                    cout << "Enter a number that is your speaker!" <<endl;
                    cin >> num;
                }
                cout << "Speaker: " << present[num-1].name << endl;
                cout << "Speaker's telephone number: " << present[num-1].teleNum
                        << endl;
                cout << "Speaker's topic: " << present[num-1].topic << endl;
                cout << "Speaker's fees: " << present[num-1].fee<< endl;
                createspace();
                break;
            case '3':
                cout << "You currently have " << numSpeaker << " speaker(s)"<<
                " to choose from." << endl;
                cout << "Which speaker would you like to change." << endl;
                cin >> num;
                while (num < 1 || num > numSpeaker)
                {
                    cout << "Enter a number that is your speaker!" <<endl;
                    cin >> num;
                }
                cin.ignore();
                cout << "Enter name of speaker: " ;
                getline (cin, present[num-1].name);
                cout << "Enter speaker's telephone number: " ;
                getline (cin, present[num-1].teleNum);
                cout << "Enter the speakers topic: " ;
                getline (cin, present[num-1].topic);
                cout << "Enter the fees speaker requires: " ;
                cin >> present[num-1].fee;
                while (present[num-1].fee < 0){
                cout << "Enter fees above 0 non negative." << endl;
                cin >> present[num-1].fee;     
                }
                cout << endl;
                //cin.ignore();
                createspace();
                break;
            case '4':
                choice = 'q';
                break;
            default: cout << "Entered a wrong choice." << endl;
               
        }
    createspace();
    } while (numSpeaker != 10 && choice != 'q');
    cout << "Quitting" << endl;
}
/*
 * Outputs a structures information.
 * returns nothing
 */
void outputData (SoccerTeam m){
    
    cout <<left<< setw(20)<< m.name << setw(15)<< m.number <<setw(15)
            <<  m.scores << endl;
}
void prob6()
{
    SoccerTeam allStars [NUMPLYRS];
    cout << "This program records a soccer team." << endl;
    cout << "Keeps track of names, player #, points scored." << endl;
    cout << "HW asks for 12 players I have set to 6, but then asks for the" 
           << endl << "total points scored by the team and who scored the most."
            << endl;
    for (int i =0; i < NUMPLYRS; i++)
    {
        cout << "Enter name of player: " ;
        getline (cin, allStars[i].name);
        cout << "Enter player's team number: " ;
        cin >> allStars[i].number;
        cout << "Enter how many points that player scored: " ;
        cin >> allStars[i].scores;
        while (allStars[i].scores < 0){
        cout << "Enter points above 0 non negative." << endl;
        cin >> allStars[i].scores;     
        }
        cout << endl;
        cin.ignore();
    }
    cout <<left<< setw(20)<< "Players Names"   << setw(15)<<"Players #"
            << setw(15)<< "Players Points" << endl;
    for (int i = 0; i < NUMPLYRS; i++)
    {
        outputData(allStars[i]);
    }
    
    int max = allStars[0].scores;
    int player =0;
    int totalPts =0;
    //setting first element to max
    totalPts += allStars[0].scores;
    for (int i =1; i < NUMPLYRS; i++){
        //totalling
        totalPts += allStars[i].scores;
        //if a element is greater then setting max to that score
        if (max < allStars[i].scores){
            max = allStars[i].scores;
        }
    }
    cout << "TOTAL POINTS SCORED: " << totalPts << " !!!!" << endl;
    for (int i =0; i < NUMPLYRS; i++){
        //going thru to see which player had max score, could be multiples
        if (allStars[i].scores == max)
        {
            cout << "Player with most points scored: " << allStars[i].name
                    << endl;
        }
    }
}
void prob4(){
    const int MONTHS = 12;
    WeatherStats year[MONTHS];
    cout << "Enter the weather data for the year starting with January" << endl
            << "and so on." << endl;
    for (int i=0; i <MONTHS; i++)
    {
        cout << "Enter temperature for month " << i+1 << " :" ;
        cin >> year[i].temp;
        while (year[i].temp < -100 || year[i].temp > 140)
        {
            cout << "Enter a temp between ranges -100 and 140 degrees "
                    "Fahrenheit."  << endl;
            cin >>year[i].temp;
        }
        
        cout << "Enter total rain fall for month " << i+1 << " :" ;
        cin >> year[i].totRain;
        while (year[i].totRain < 0){
            cout << "Enter a number 0 or greater." << endl;
            cin >> year[i].totRain;
        }
        cout << endl << endl;
    }
    float findHigh = 1;
    int m1=0;
    int m2=0;
    float findLow = 10000;
    //high
    for (int i=0; i <MONTHS; i++)
    {
        if (year[i].temp > findHigh){
            findHigh = year[i].temp;
            m1 = i;
        }
        //
        if (year[i].temp < findLow){
            findLow = year[i].temp; 
            m2 = i;
        }
    }
    float totalRain=0;
    float totalTemp=0;
    for (int i =0; i < MONTHS; i++){
        totalRain += year[i].totRain;
        totalTemp += year[i].temp; 
    }
    
    cout << "The total rainfall for the year was: " << totalRain << endl;  
    cout << "The highest temperature was: " << findHigh ;
    cout << "    In month: " << m1+1 <<endl;
    cout << "The lowest temperature was: " << findLow ;
    cout << "    In month: " << m2+1 << endl;
    cout << "The average rainfall of the year was: " << fixed<<setprecision(1)<<
            static_cast<float>(totalRain/MONTHS) << endl;
    cout << "The average temperature for all the months was: " <<
            static_cast<float>(totalTemp/MONTHS) << endl;
}
/*
 * This function returns a structure with the user entering all given 
 * information. Once the user has entered all the info it returns that struct.
 */
MovieData getInfo (){
    MovieData m;
    
    cout << "Enter the title of the movie : ";
    getline (cin, m.title);
    cout << "Enter who directed the movie: ";
    getline(cin, m.director);
    //cin.ignore();
    cout << "Enter year movie was released: ";
    cin >> m.year;
    
    cout << "Enter how long the movie is in minutes: " ;
    cin >> m.runTime;
    cout << "Enter the production cost of movie: $" ;
    cin >> m.cost;
    cout << "Enter first year's revenue for movie: $" ;
    cin >> m.revenue;
    cin.ignore();
    return m;
}
/*
 * This function outputs a structures data 
 * returns nothing
 */
void output2 (MovieData m){
    //MovieData m;
    cout << "Movie: " << m.title << endl;
    cout << "Director: " << m.director << endl;
    cout << "Released year: " << m.year << endl;
    cout << "Runtime in minutes: " << m.runTime << endl;
    cout << fixed << setprecision(2);
    cout << "After the first year profit is: $" << m.revenue -m.cost  << endl;
}
void prob2(){
    MovieData movie1;
    MovieData movie2;
    cout << "This program lets you enter two movies and some data about them."
            <<endl;
    cout << "User can enter title, director, year released, and runtime of "
            "movie" << endl;
    movie1 =getInfo ();
    cout << endl;
    movie2 =getInfo ();
    cout << endl;
    output2 (movie1);
    cout << endl;
    output2 (movie2);
}
/*
 * Initializing a structure
 */
void inputData1(SodaMachine *list)
{
    list[0].soda = "Cola";
    list[0].cost = 0.75;
    list[1].soda = "Root Beer";
    list[1].cost = 0.75;
    list[2].soda = "Lemon-Lime";
    list[2].cost = 0.75;
    list[3].soda = "Grape Soda";
    list[3].cost = 0.80;
    list[4].soda = "Cream Soda";
    list[4].cost = 0.80;
    for (int i =0; i < SODAS; i++)
    {
         list[i].numLeft = 20;
    }
}
/*
 * outputs a chart of struct SodaMachine
 */
void output1 (SodaMachine *list)
{
    cout <<left<< setw(15)<< "Drink Name"   << setw(12)<<"Cost"
            << setw(12)<< "Number Left" << endl;
    cout <<"------------------------------------------" << endl;
    for (int i= 0; i < SODAS; i++)
    {
        cout << (i+1) << ". " <<left<< setw(15)<< list[i].soda  << setw(12)
                <<fixed << setprecision(2)
                <<list[i].cost << setw(12)<< list[i].numLeft<< endl;
    }
}
void prob13(){
    cout << "This program is a semi simulated menu soda drink machine." << endl;
    cout << "Lists the drinks to the screen and prompts the user to quit or" <<
            endl << "pick a drink." << endl;
    cout << "User enters amount of money to be inserted then receives change"
            << endl << "according to amount input. If a particular soda is "
            "sold out," << endl << "it will say sold out." << endl << endl;
    char choice;
    int sodaChoice;
    float change;
    SodaMachine list[SODAS];
    inputData1(list);
    do{    
        output1 (list);
        cout << "Enter a number 1 through 4 to which soda you would like to " <<
                endl << "buy: " << endl;
        cin >> sodaChoice;
        while (sodaChoice < 1 || sodaChoice > 5){
            cout << "Enter number 1-4 only." << endl;
            cin >> sodaChoice;
        }
        if (list[sodaChoice-1].numLeft == 0)
        {
            cout << "That drink is SOLD OUT!!!" << endl << endl;
        }
        else{
            cout << "Enter how much change you are putting into the machine: " <<
                  endl;
            cin >> change;
            while (change > 1) {
                cout << "Machine only accepts a dollar or less." << endl;
                cin >> change;       
            }
            while (change < 0 || change < list[sodaChoice-1].cost){
                cout << "You didnt enter enough change." << endl;
                cin >> change;
            }
            cout << "Amount received back is: " <<fixed << setprecision(2)
                 <<"$"<< (change - list[sodaChoice-1].cost) << endl;
            list[sodaChoice-1].numLeft--;
        }
        
        cout << "Would you like to pick another drink or quit. Hit 'q' or 'Q'"
                " to quit." << endl << "Anything else to pick a drink." << endl;
        cin >> choice;
    }while (toupper(choice) != 'Q');

}
void prob10(){
    Speakers present[NUM];
    int numSpeaker = 0;
    cout << "This program lets the user enter data for a speaker at a bureau." 
            << endl << "User is then prompted with menu driven program to do"
            " as they wish." << endl;
    cout << "MAX speakers allowed to be inputted is 9." << endl;
    cout << "Program will terminate if another is attempted to be added." << 
            endl;
    char choice;
    //int num=0;
    do{
        char probChoice;
        int num=0;
        menu2 (probChoice);
        
        switch(probChoice)
        {
            case '1':
                cin.ignore();
                cout << "Enter name of speaker: " ;
                getline (cin, present[numSpeaker].name);
                cout << "Enter speaker's telephone number: " ;
                getline (cin, present[numSpeaker].teleNum);
                cout << "Enter the speakers topic: " ;
                getline (cin, present[numSpeaker].topic);
                cout << "Enter the fees speaker requires: " ;
                cin >> present[numSpeaker].fee;
                while (present[numSpeaker].fee < 0){
                cout << "Enter fees above 0 non negative." << endl;
                cin >> present[numSpeaker].fee;     
                }
                cout << endl;
                //cin.ignore();
                numSpeaker++;
                createspace();
                break;
            case '2':
                cout << "You currently have " << numSpeaker << " speaker(s)"<<
                " to choose from." << endl;
                cout << "Which speaker would you like to output." << endl;
                cin >> num;
                while (num < 1 || num > numSpeaker)
                {
                    cout << "Enter a number that is your speaker!" <<endl;
                    cin >> num;
                }
                cout << "Speaker: " << present[num-1].name << endl;
                cout << "Speaker's telephone number: " << present[num-1].teleNum
                        << endl;
                cout << "Speaker's topic: " << present[num-1].topic << endl;
                cout << "Speaker's fees: " << present[num-1].fee<< endl;
                createspace();
                break;
            case '3':
                cout << "You currently have " << numSpeaker << " speaker(s)"<<
                " to choose from." << endl;
                cout << "Which speaker would you like to change." << endl;
                cin >> num;
                while (num < 1 || num > numSpeaker)
                {
                    cout << "Enter a number that is your speaker!" <<endl;
                    cin >> num;
                }
                cin.ignore();
                cout << "Enter name of speaker: " ;
                getline (cin, present[num-1].name);
                cout << "Enter speaker's telephone number: " ;
                getline (cin, present[num-1].teleNum);
                cout << "Enter the speakers topic: " ;
                getline (cin, present[num-1].topic);
                cout << "Enter the fees speaker requires: " ;
                cin >> present[num-1].fee;
                while (present[num-1].fee < 0){
                cout << "Enter fees above 0 non negative." << endl;
                cin >> present[num-1].fee;     
                }
                cout << endl;
                //cin.ignore();
                createspace();
                break;
            case'4':
                searchFor (present);
                break;
            case '5':
                choice = 'q';
                break;
            default: cout << "Entered a wrong choice." << endl;
               
        }
    createspace();
    } while (numSpeaker != 10 && choice != 'q');
    cout << "Quitting" << endl;
}
void searchFor (Speakers *m){
    string word;
    cout << "Enter the topic you would like to search for: " << endl;
    cin >> word;
    bool found;
    for (int i =0; i < NUM; i++)
    {
        if (word == m[i].topic){
            cout << "Speaker: " << m[i].name << endl;
                cout << "Speaker's telephone number: " << m[i].teleNum
                        << endl;
                cout << "Speaker's topic: " << m[i].topic << endl;
                cout << "Speaker's fees: " << m[i].fee<< endl;
        }
        else{
            found = false;
        }
    }
    if (found ==false)
    {
        cout << "No match was found !!! " << endl;           
    }
}
void prob1()
{
    MovieData1 m;
    MovieData1 m2;
    cout << "Enter the title of the movie : ";
    getline (cin, m.title);
    cout << "Enter who directed the movie: ";
    getline(cin, m.director);
    //cin.ignore();
    cout << "Enter year movie was released: ";
    cin >> m.year;
    
    cout << "Enter how long the movie is in minutes: " ;
    cin >> m.runTime;
    cin.ignore();
    cout << "Enter the title of the movie : ";
    getline (cin, m2.title);
    cout << "Enter who directed the movie: ";
    getline(cin, m2.director);
    //cin.ignore();
    cout << "Enter year movie was released: ";
    cin >> m2.year;
    
    cout << "Enter how long the movie is in minutes: " ;
    cin >> m2.runTime;
    cin.ignore();
    output3 (m);
    output3 (m2);
}
void output3 (MovieData1 m){
    //MovieData m;
    cout << "Movie: " << m.title << endl;
    cout << "Director: " << m.director << endl;
    cout << "Released year: " << m.year << endl;
    cout << "Runtime in minutes: " << m.runTime << endl;   
}