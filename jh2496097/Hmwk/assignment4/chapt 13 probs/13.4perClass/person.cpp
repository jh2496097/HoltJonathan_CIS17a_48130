/**
 * Jonathan Holt
 * person class implementation
 */
#include "person.h"

Person::Person(){
    name = "";
    address = "";
    age =0;
    phoneN ="0"; 
}
Person::Person(string n, string addr, int a, string p){
    name =n;
    address =addr;
    if (a < 1)
        age =0;
    else
        age =a;
    int length;
    length = p.size();
    if (length != 10)
    {
        phoneN ="invalid input";
    }
    else
        phoneN=p;
}
void Person::setAddr(string addr){
    address = addr;
}
void Person::setAge(int a){
    if(a < 1)
        age = 0;
    else
        age =a;
}
void Person::setName(string n){
    name = n;
}
void Person::setPhoneN(string p){
    bool valid=true;
    for (int i=0; i < p.size();i++){
        if(isalpha(p[i])){
            valid = false;
        }         
    }
    int length = p.size();
    if (length != 10|| !valid)
    {
        phoneN ="invalid #";
    }
    else
        phoneN=p;
}
string Person::getName() const{
    return name;
}
int Person::getAge() const{
    return age;
}
string Person::getAddr()const{
    return address;
}
string Person::getPhoneN() const{
    return phoneN;
}