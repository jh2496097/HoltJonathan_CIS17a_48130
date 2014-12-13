#include "savingsaccount.h"
#include <iostream>

using namespace std;
SavingsAccount::SavingsAccount(float acct){
    if (acct >= 0)
        balance = acct;
    else
        balance =0;
    
    freqWithDraw =0;                  //Property
    freqDeposit=0;
}
void SavingsAccount::Transaction(float num){
    if (num > 0){
        balance = balance + Deposit(num);
    }
    else
        balance = balance + Withdraw(num);
}
float SavingsAccount::Deposit(float dNum){
    freqDeposit++;
    return dNum;
}
float SavingsAccount::Withdraw(float wNum){
    //cout << "b"<<balance<<endl;
    //cout << "w"<<wNum << endl;
    float temp = balance;
    if (temp+wNum < 0){
        cout << "WithDraw not Allowed"<<endl;
        wNum = 0;
    }
    
    freqWithDraw++;
    return wNum;
}
float SavingsAccount::Total(float savint, int time){
    float interest = savint +1;
    float b = balance;
    for (int i =0; i < time; i++){
        b *= interest;
    }
    return b;
}
float SavingsAccount::TotalRecursive(float savint, int time){
    float interest = savint +1;
        //cout<<"b"<<balance<<endl;
        if (time ==0){
            return balance;
        }
        else
            return interest*TotalRecursive(savint, --time);           
}
void SavingsAccount::toString(){
    cout << "Balance: " << balance << endl;
    cout << "Withdraws: " << freqWithDraw << endl;
    cout << "Deposits: " << freqDeposit << endl;
}