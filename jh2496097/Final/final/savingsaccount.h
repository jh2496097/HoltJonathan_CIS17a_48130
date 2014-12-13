/* 
 * File:   savingsaccount.h
 * Author: Jonathan
 *
 * Created on December 8, 2014, 3:18 PM
 */

#ifndef SAVINGSACCOUNT_H
#define	SAVINGSACCOUNT_H
class SavingsAccount{
    private:
		float Withdraw(float);               //Utility Procedure
		float Deposit(float);                //Utility Procedure
		float balance;                       //Property
		int   freqWithDraw;                  //Property
		int   freqDeposit;
   public:
		SavingsAccount(float);               //Constructor
		void  Transaction(float);            //Procedure
		float Total(float=0,int=0);	         //Savings Procedure
		float TotalRecursive(float=0,int=0);
		void  toString();
                float getBalance(){return balance;}//Output Properties
	                   //Property
};
#endif	/* SAVINGSACCOUNT_H */

