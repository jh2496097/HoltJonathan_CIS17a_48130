/* 
 * Jonathan Holt
 * C++ objects
 * assignment 4
 * i certify this is my work
 * Created on November 1, 2014, 7:14 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "person.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout <<"This program lets user enter information about them self to the "
            "console." <<endl <<"It then displays all the created objects in"
            " the program running."<<endl<<"Takes into account user input "
            "validation for age and phone number."<<endl<<"If age is a "
            "negative number age is set to 0 and if phone number" <<endl<<
            "is not 10 consecutive numbers or contains an alphabet outputs "
            "invalid #" <<endl;

    //1st object
    Person you;
    string name;
    string addr;
    int num;
    string phone;
    int length;
    cout <<"Enter the information for yourself: " <<endl;
    cout << "Enter your name: ";
    getline (cin, name);
    you.setName(name);
    cout <<"Enter your address: ";
    getline (cin, addr);
    you.setAddr(addr);
    cout <<"Enter your age: ";
    cin >> num;
    you.setAge(num);
    cout <<"Enter your phone # ex(5555051551): ";
    cin >> phone;
    you.setPhoneN(phone);
    
    //2nd object
    Person me ("Jonathan Holt", "99999 Cool dr.", 25, "9095555454");
    cout << setw(15) <<"Name:"<<setw(20)<<"Address:"<<
            setw(7)<<"Age:" <<setw(12)<<"Phone:" <<endl; 
    cout << setw(15) <<me.getName()<<setw(20)<<me.getAddr()<<
            setw(7)<<me.getAge() <<setw(12)<<me.getPhoneN() <<endl; 
    //third object
    Person sister;
    sister.setName("Mary ann Holt");
    sister.setAddr("99999 Cool dr.");
    sister.setAge(24);
    sister.setPhoneN("90955543");
    cout << setw(15) <<sister.getName()<<setw(20)<<sister.getAddr()<<
            setw(7)<<sister.getAge() <<setw(12)<<sister.getPhoneN() <<endl; 
    //outputting third
    cout << setw(15) <<you.getName()<<setw(20)<<you.getAddr()<<
            setw(7)<<you.getAge() <<setw(12)<<you.getPhoneN() <<endl;
    
    return 0;
}

