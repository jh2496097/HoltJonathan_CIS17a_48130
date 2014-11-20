/* 
 * File:   person.h
 * Author: Jonathan
 *
 * Created on November 1, 2014, 7:16 PM
 */

#ifndef PERSON_H
#define	PERSON_H
#include <string>
using namespace std;
class Person{
    private:
        string name;
        string address;
        int age;
        string phoneN;
    public:
        //constructors
        Person();
        Person(string, string, int, string);
        //setters
        void setName (string);
        void setAddr(string);
        void setAge (int);
        void setPhoneN(string);
        //getters
        string getName()const;
        //{ return name;}
        string getAddr()const;
        int getAge ()const;
        string getPhoneN() const;
    
};

#endif	/* PERSON_H */

