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
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

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
    cout << "\nThere is currently " << lowCount << " lowercase letters." << endl;
    cout << "There is currently " << upCount << " uppercase letters." << endl;
    cout << "There is currently " << numCount << " numbers." << endl;
    cout << endl;
    
    infile.close("text.txt");
    return 0;
}

