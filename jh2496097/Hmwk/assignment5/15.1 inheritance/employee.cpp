
#include "employee.h"

//implementation of employee class

Employee::Employee(){
    name = "";
    empNum = "";
    hire = "--/--/--";
}
Employee::Employee(string n, string e, string h){
    name = n;
    empNum = e;
    hire = h;
}
void Employee::setEmpNum(string e){
    if (e.length() == 5)
        empNum = e;
    else
        empNum = "invalid employee number";
}
void Employee::setHire(string h){
    hire = h;
}
void Employee::setName(string n){
    name = n;
}
