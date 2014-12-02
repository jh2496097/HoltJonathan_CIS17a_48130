/* 
 * File:   employee.h
 * Author: Jonathan
 *
 * Created on November 25, 2014, 10:21 AM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <string>
using namespace std;

class Employee{
    private:
        string name;
        string empNum;
        string hire;
    public:
        Employee();
        Employee(string, string, string);
        void setName (string);
        void setEmpNum (string);
        void setHire (string);
        string getName ()const{return name;}
        string getEmpNum ()const{return empNum;}
        string getHire ()const{return hire;}
};

#endif	/* EMPLOYEE_H */

