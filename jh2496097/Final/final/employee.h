/* 
 * File:   employee.h
 * Author: Jonathan
 *
 * Created on December 8, 2014, 3:20 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <string>
using namespace std;
class Employee{
    private:
		float Tax(float);      //Utility Procedure
		string   MyName;      //Property
		string   JobTitle;    //Property
		float  HourlyRate;      //Property
		int    HoursWorked;     //Property
		float  GrossPay;        //Property
		float  NetPay;          //Property        		
    public:
		Employee(string,string,float);  //Constructor
		float  CalculatePay(float,int); //Procedure
		float  getGrossPay(float,int);  //Procedure
		float  getNetPay(float);        //Procedure
		void   toString();              //Procedure
		int   setHoursWorked(int);     //Procedure
		float   setHourlyRate(float);    //Procedure
};

#endif	/* EMPLOYEE_H */

