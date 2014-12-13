/* 
 * File:   main.cpp
 * Author: Jonathan
 *
 * Created on December 12, 2014, 3:21 PM
 */

#include <cstdlib>
#include "employee.h"
#include "prob1random.h"
#include "prob2sort.h"
#include "prob3tableinherit.h"
#include "savingsaccount.h"

using namespace std;

/*
 * 
 */
void createspace();
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
int main(int argc, char** argv) {

        srand(time(NULL));
    //choice to end do while
    char choice;
    do
    {
        //choice for problems
        char probChoice;
        
        cout << "This is a my final." << endl;
        cout << "All problems working except number 2. Thank you for a great"
                " semester" <<endl; 
        cout << "Choose between the numbers 1 to 5" << endl;
        cout << "1. Rand set" << endl;
        cout << "2. Sorting*not working only sorts a column*" << endl;
        cout << "3. Adding table" << endl;
        cout << "4. Savings" << endl;
        cout << "5. Employee" << endl;
        cin >> probChoice;
        
        switch (probChoice)
                {
                case '1': 
                    createspace();
                    problem1();
                    
                break;
                case '2': 
                    createspace();
                    problem2();
                    
                break;
                case '3': 
                    createspace();
                    problem3();
                    
                break;
                case '4': 
                    createspace();
                    problem4();
                    
                break;
                case '5': 
                    createspace();                    
                    problem5();

                break;
            
            default: cout << "You entered a wrong choice\n";
            createspace();
        }
        createspace();
        cout << "Do you wish to quit type 'q' or 'Q' another anything else " << 
                endl << "to continue: " << endl;
        cin >> choice;
    }while(toupper(choice) != 'Q');
    
    return 0;
}
/*
 * creates space for easier reading
 */
void createspace()
{
    for (int i=0 ; i < 4; i++)
    {
        cout << endl;
    }
}
void problem5(){
    cout << "Problem number 5 for final!!!!"<<endl <<endl;
    Employee Mark("Mark","Boss",215.50);
	Mark.setHoursWorked(-3);
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(20.0),
		Mark.setHoursWorked(25));
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(40.0),
		Mark.setHoursWorked(25));
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(60.0),
		Mark.setHoursWorked(25));
	Mark.toString();
        cout<<endl<<endl;
	Employee Mary("Mary","VP",50.0);
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(40));
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(50));
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(60));
	Mary.toString();
}
void problem4(){
    SavingsAccount mine(-300);

	for(int i=1;i<=10;i++)
	{
		mine.Transaction((float)(rand()%500)*(rand()%3-1));
                //cout << mine.getBalance() << endl;
	}
	mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
		<<mine.Total((float)(0.10),7)<<endl;
    //cout<< "\nThe recursive function is not working." <<endl;
    cout<<"Balance after 7 years given 10% interest = "
		<<mine.TotalRecursive((float)(0.10),7)
		<<" Recursive Calculation "<<endl;
}
void problem3(){
    cout<<"Entering problem number 3"<<endl;
	int rows=5;
	int cols=6;
	Prob3TableInherited tab("Problem3.txt",rows,cols);
	const int *naugT=tab.getTable();
        //const int *naugC=tab.getColSum();
        //const int *naugR=tab.getRowSum();
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<naugT[i*cols+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
        cout << "NEW TABLE " << endl << endl;
	const int *augT=tab.getAugTable();
	for(int i=0;i<=rows;i++)
	{
		for(int j=0;j<=cols;j++)
		{
			cout<<augT[i*(cols+1)+j]<<" ";
		}
		cout<<endl;
	}
}
void problem2(){
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    Prob2Sort rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    cout<<endl;
    cout<<"\nSorting on which column"<<endl;//one line has 16 characters 14 visible
    int column;
    cin>>column;
    while (column < 0 || column > 14){
        cout <<"Only 0-14 for columns: " ;
        cin >> column;
    }
    char line[10];
    for (int i=0;i<10;i++){
         cout << ch2p[i*17+column] << " ";
         line[i] = ch2p[i*17+column];
    }
    cout <<endl;
    bool up;
    char temp;
    do
    {
        up = false;
        for (int i = 0; i < 10-1; (i++))
        {  
            //cout <<"*"<< ch2p[i*17+column];
            if(line[i] > line[i+1])
            {
                temp = line[i];
                line[i]=line[i+1];
                line[i+1] = temp;
                up = true;
            }               
        }
    }while (up);
for (int i=0;i<10;i++){
         cout << line[i] << " ";
         //line[i] = ch2p[i*17+column];
    }
    cout << endl<<endl;
cout << endl<<endl;
    
    /*char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<16;j++)
        {
	    cout<<zc[i*16+j];
        }
    }*/
    //delete []ch2;
    delete []ch2p;
    cout<<endl;    
    
}
void problem1(){

    char n=5;
    unsigned char rndseq[]={16,34,57,79,144};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
	a.randFromSet();
    }
    int *x=a.getFreq();
    unsigned char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
	cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}