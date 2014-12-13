
#include "employee.h"
#include <iostream>
using namespace std;
Employee::Employee(string n, string t, float wage){
    MyName = n;
    JobTitle = t;
    HourlyRate = wage;
    HoursWorked=0;     //Property
    GrossPay=0;        //Property
    NetPay =0;  
}
float Employee::Tax(float gross_pay){
    //GrossPay = gross_pay;
    float taxCheck;
    if (gross_pay <= 500){
        taxCheck = 0.1;
    }
    else if (gross_pay > 500 || gross_pay <= 1000){
        taxCheck = 0.2;
    }
    else{
        taxCheck = 0.3;
    }
    return taxCheck;
}
//setters
float Employee::setHourlyRate(float hourRate){
        HourlyRate = hourRate;
    
    return HourlyRate;
}
int Employee::setHoursWorked(int hourWork){
        HoursWorked = hourWork;
    
    return HoursWorked;
}

void Employee::toString(){
    if (HourlyRate < 0 || HourlyRate >200){
        cout << "Unacceptable Hourly Rate"<<endl;
        HourlyRate = 0;
    }
    if (HoursWorked < 0 || HoursWorked > 84)
    {
        cout << "Unacceptable Hours Worked"<<endl;
        HoursWorked =0;
    }
    //getGrossPay(HourlyRate, HoursWorked);
    cout << "Name = " << MyName << " Job Title = " << JobTitle<<endl;
    cout << " Hourly Rate = " << HourlyRate << " Hours Worked = " << HoursWorked
            << " Gross Pay = " << GrossPay << " Net Pay = " << NetPay <<endl;
}
float Employee::getGrossPay(float hourR, int hourW){
        int totalHours = hourW;
        float pay1=0;
        float pay2=0;
        float pay3=0;
        int temp;
        if (totalHours > 50 ){
            temp = hourW - 50;
            //cout <<"triple: " << temp<<endl;
            pay3 = (HourlyRate * 2) * temp;
            totalHours -= temp;
        }
        if (totalHours > 40 ){
            temp = totalHours - 40;
            //cout <<"double: "<< temp <<endl;
            pay2 = (HourlyRate * 1.5) * temp;
            totalHours -= temp;
        }
        //tripleTime = workers[i].hours % 20;
        //doubleTime = workers[i].hours % 20;
        if (totalHours <= 40 ){
            pay1 = HourlyRate * totalHours;
            //cout <<"single:" <<totalHours<<endl;
        }
        GrossPay = pay1+pay2+pay3;
        return GrossPay;
}
float Employee::CalculatePay(float hourR, int hourW){
    getGrossPay(HourlyRate, HoursWorked);
    int pay1=0,pay2=0,pay3=0;
    int tempPay = GrossPay;
    
    if (tempPay >= 500){
        int tax= 500*Tax(500);
        pay1 = tax;//GrossPay - tax;
        tempPay = tempPay - 500;
    }
    if (tempPay >= 500 ){//|| tempPay <= 1000
        int tax= 500*Tax(1000);
        pay2 = tax;//GrossPay - tax;
        tempPay = tempPay - 500;
    }
    if(tempPay >= 0){
        //cout << "temppay..."<<tempPay<<endl;
        int tax= tempPay*.3;
        pay3 = tax;//GrossPay - tax;
        tempPay = tempPay - tempPay;
    }
    
    //cout << "pay 1 2 3..." << pay1 << " " << pay2<<" " <<pay3<<endl;
    NetPay = GrossPay-pay1-pay2-pay3;
    return NetPay;
}