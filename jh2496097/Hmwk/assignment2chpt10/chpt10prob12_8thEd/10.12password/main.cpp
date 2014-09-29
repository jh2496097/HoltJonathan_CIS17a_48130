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
int main(int argc, char** argv) {

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
    return 0;
}

