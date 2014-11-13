/**
 * Jonathan Holt
 * class cpp file
 */
#include "employee.h"
using namespace std;
//constructors
Employee::Employee(){
    name ="null";
    idNum =0;
    department ="null";
    position = "null";
}
Employee::Employee(string n, int num){
    name = n;
    if (num < 1 || num >= 100000){
        //cout <<"invalid ID set to 0."<<endl;
        idNum =0;
    }
    else
    idNum = num;
    department ="";
    position = "";
}
Employee::Employee(string n, int num, string d, string p){
    name = n;
    if (num < 1 || num >= 100000){
        //cout <<"invalid ID set to 0."<<endl;
        idNum =0;
    }
    else
    idNum = num;
    department = d;
    position = p;
}
//setters
void Employee::setName(string n){
    name =n;
}
void Employee::setNum(int num){
    if (num < 1 || num >= 100000){
        //cout <<"invalid ID set to 0."<<endl;
        idNum =0;
    }
    else
    idNum =num;
}
void Employee::setDepart(string d){
    department =d;
}
void Employee::setTitle(string t){
    position =t;
}
//getters
string Employee::getName()const{
    return name;
}
int Employee::getID()const {
    return idNum;
}
string Employee::getDepart()const {
    return department;
}
string Employee::getTitle()const{
    return position;
}
