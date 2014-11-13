/*
 * Jonathan Holt
 * Midterm
 * Dr. Lehr
 * i certify this is my work
 */

//Library includes Here!!!
#include <iostream>
using namespace std;
struct CustmrChk{
    string acctNum;
    int *ptr;
    int balance;
};
struct Payout{
    string name;
    float payRate;
    int hours;
    float pay;
    int size;
};
struct StatsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};
//Global Constants Here!!!

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
//prob1
void problem1();
void accessCustmr (CustmrChk *m, int &spot, int customers);
CustmrChk *Acct(CustmrChk *, int num, int userChoice);
void output(CustmrChk *m, int num);
void menu (char &c);
//prob2
void problem2();
void output2(Payout *m);
Payout *pay(Payout *, int num);
//prob3
void problem3();
StatsResult *avgMedMode(int *,int);
void printstat(StatsResult *);
//Function Prototypes
int *fillArray(int,int);
void printArray(int *,int,int);
void printMode(int *);
int *sort(int *,int);
int *mode(int *,int);
float mean (int *, int );
float median(int *,int);
//prob4
void problem4();
int realNum (int n);
void encrpyt (int *p, int size);
void decrpyt (int *p, int size);

void problem5();

void problem6();

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
            cout<<endl;
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
        cout<<"In problem # 1"<<endl<<endl;
        char choice;
    int userChoice;
    int numCust=0;
    char c;
    int length;
    int numChecks=0;
    int check;
    int checkTotal=0;
    int numDeposits=0;
    int deposit;
    int depositTotal=0;
    cout<<"Doesn't check for repeated account numbers..." <<endl;
    cout<<"Didnt get to incorporate created function\n"
            "'CustmrChk *Acct(CustmrChk *, int num, int userChoice);'\n"
            " in this prob..(fixed function working)"<<endl<<endl;
    cout<<"Please enter how many customers you will be dealing with today: ";
    cin >> numCust;
    while(numCust < 1){
        cout<<"Please enter a number 1 or greater!!!"<<endl;
        cin >>numCust;
    }
    //const int NUM = people.customers;
    CustmrChk *people = new CustmrChk [numCust];
    for(int i=0; i < numCust;i++){
        people[i].balance =0;
    }
    do{
        cout<<endl;
        menu (c);
        
        switch (c)
        {
            case '1':
                
                accessCustmr (people, userChoice, numCust);
                
                people = Acct(people, numCust, userChoice);
                
                break;
            case '2':
                accessCustmr (people, userChoice, numCust);
                output(people, userChoice);
                break;
            
            case '3':
                choice ='q';
                break;
            default: cout<<"Entered a wrong choice!"<<endl;
        }
        //people = new CustmrChk [people.customers];
        //people = new CustmrChk [NUM];
        //CustmrChk people2 [people.customers];
        
    }while (toupper(choice) != 'Q');
    
    //delete []people->ptr;
    delete []people;
}

void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
        int numEmps=0;
    int tripleTime;
    int doubleTime;
    char choice;
    //do{
        
        cout <<"Enter how many employees you wish to payout this weeks checks."
                <<endl;
        cin >> numEmps;
        if(numEmps < 1 ){
           cout<<"Enter a number greater than 0 for number!" <<endl;
           cin>>numEmps;            
        }
        Payout *workers = new Payout [numEmps];
        workers->size=numEmps;
        workers = pay(workers, numEmps);
    
        output2(workers);
        //cout << "Do you wish to quit press 'q' or 'Q' or anything else to replay"
        //    <<endl;
        //cin >> choice;
    
        delete [] workers;
    //}while (toupper(choice) != 'Q');
    
}

void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
        int arraySize=0;
    float mean1, median1;
    
    //Create the array
    cout <<"How big would you like to make the array?" ;
    cin >>arraySize;
    while (arraySize < 1){
        cout <<"Enter a number bigger than 1!!!!" <<endl;
        cin >> arraySize;
    }
    
    //StatsResult stats;// = new StatsResult [arraySize];
    int *array=fillArray(arraySize,5);
    
    StatsResult *stats;// = new StatsResult;
    stats = avgMedMode(array,arraySize);
    
    
    printstat(stats);
    
    delete []array;
    delete []stats->mode;
    delete stats;
}

void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    cout<<"Didnt have to allocate memory but did." <<endl;
    string digit;
    int length;
    const int SIZE=4;
    cout<<"This program is a decryption program it ask user to enter a\n4 "
            "digit number and numbers cant be greater than 7." <<endl;
    cout<<"Number can only be 4 digits and no higher than 7  " <<endl;
    cout <<"higher than 7." <<endl;
    //do{
    cout<<"Please enter the number:"<<endl;
    //ONE CIN statement
    cin >> digit;
    length = digit.size();
    //cout << length <<endl;
    while (length != 4 || isalpha(digit[0]) && isalpha(digit[1])
            && isalpha(digit[2]) &&isalpha(digit[3]) || digit[0] =='-'||
            digit[0] > '7' || digit[1] > '7' || digit[2] >'7' ||digit[3] >'7'){
        cout <<"The number you entered was not correct and contained less or"
                " more" <<endl <<"than 4 digits or had a letter in it !!"<<endl;
        cout <<"OR one of your digits was higher than 7!"<<endl;
        //ONE CIN statement
        cin >> digit;
        length = digit.size();
        //cout << length <<endl;
    }
    int *ptr = new int [SIZE];
    //int num, num1, num2, num3;
    for (int i=0; i <SIZE;i++){
        ptr[i] = realNum (digit[i]);
    }
    /*ptr[0] = realNum (digit[0]);
    num1 = realNum (digit[1]);
    num2 = realNum (digit[2]);
    num3 = realNum (digit[3]);*/
    /*cout << "number is: " << num << "  " << num1 << "  " <<num2 << "  " <<
            num3 << "  " <<endl;*/
    cout <<"ENCRYPTED!" <<endl;
    encrpyt (ptr, SIZE);
    cout << "number is: ";
    for (int i=0; i < SIZE; i++){
        cout << *(ptr +i) << "  ";
    }
    cout <<endl;
    
    cout <<"DECRYPTED!" <<endl;
    decrpyt (ptr, SIZE);
    cout << "number is: ";
    for (int i=0; i < SIZE; i++){
        cout << *(ptr +i) << "  ";
    }
    cout <<endl;
    
    //}while(true);
    
    delete ptr;
}

void problem5(){
    int num=0;
    short factorial=1;
    cout<<"In problem # 5"<<endl<<endl;
    cout<<"PART A!!"<<endl;
    cout<<"I do not think there is a numerical data type variable that is only"
            <<endl<<"a byte. However, a char variable is 1 byte or 8 bits. "
            <<endl;
    
    cout <<"Enter your factorial number: ";
    cin >> num;
    if (num==0)
    {
        factorial = 1;
    }
    else
    {
        for (int i =1; i <= num;i++){
            factorial *= i;
            cout << factorial<<endl;
        } 
    }
    cout << "The number is: " << factorial<< endl<<endl;
    
    cout<<"PART B!!"<<endl;
    cout<<"'short int' largest factorial was: 7 "<<endl;
    cout<<"'signed short int' largest factorial was: 7"<<endl;
    cout<<"'unsigned short int' largest factorial was: 8"<<endl;
    cout<<"'int' largest factorial was: 12"<<endl;
    cout<<"'signed int' largest factorial was: 12"<<endl;
    cout<<"'unsigned int' largest factorial was: 12"<<endl;
    cout<<"'long int' largest factorial was: 20"<<endl;
    cout<<"'signed long int' largest factorial was: 20"<<endl;
    cout<<"'unsigned long int' largest factorial was: 20"<<endl;
    cout<<"'long long int' largest factorial was: 20"<<endl;
    cout<<"'unsigned long long int' largest factorial was: 20"<<endl;
    cout<<"'float' largest factorial was: 34 then i get 'inf' 35+"<<endl;
    cout<<"'double' largest factorial was: 170 then i get 'inf' 171+"<<endl;
    cout<<"'long double' largest factorial was: IDK was scarred to go higher"
            " than 1000"<<endl <<endl <<endl;
}

void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
        cout <<"PART A"<<endl;
        cout<<"Converted 2.125 to the following conversions: " << endl;
        cout << "OCTAL: 2.1     HEX: 2.2     BINARY: 0010.0010" <<endl<<endl;
        cout <<"Converted 0.06640625 to the following:"<<endl;
        cout <<"OCTAL: 0.042    HEX: 0.11    BINARY: 0.00010001"<<endl<<endl;
        cout <<"Floating Point representation:"<<endl;
        cout<<"First did 0.06640625 took binary of 0.00010001 and took that"
                <<endl<<"to the neg 3 power of 2"<<endl;
    cout <<"To represent neg 3 power of 2(2^-3) in float power i took 00000011"<<endl;
        cout <<"              I then took the invert which is 11111100 "<<endl;
        cout <<"then added 1 to give me                       11111101" <<endl;
        cout << "Since i moved to the neg 3 power my representation is: "<<endl;
        cout << "0.1000100   00000000  00000000  11111101" <<endl;
        cout << "\t\tANSWER IS: 440000FD "<<endl<<endl;
    cout <<"Second did -2.125 but worked with the positive binary first\n"
             <<"So i took 2.125 binary 0010.0010 to the pos 2 power of 2(2^2)"<<
                endl;
        cout <<"This float representation gave me:"<<endl;
    cout<<"0.1000100  00000000  00000000  00000010 since i need the neg# i invert" 
            <<endl;
    cout<<"1.0111011  11111111  11111111   ignored"<<endl;
        cout<<"                            1     add1"<<endl;
        cout<<"1.0111100  00000000  00000000  00000010"<<endl;
        cout<<"\t\tANSWER IS: BC000002"<<endl<<endl;
        cout<<"\n\nPART B"<<endl;
        cout<<"Converting float representations to decimal"<<endl;
        cout<<"First:4 6      6 6        6 6       01"<<endl;
        cout<<"0.1000110    01100110   01100110  00000001"<<endl;
        cout<<"Since to the power of 1 it moves over 1 giving me"<<endl;
        cout<<"1.  0001  1001 1001 1001 1001 1000"<<endl;
        cout<<"1.  1     9    9    9    9    8 HEX with these i convert:"<<endl;
    cout<<" 1x16^-1+ 9x16^-2+ 9x16^-3+ 9x16^-4+ 9x16^-5 +8x16^-6=0.09999990463\n";
        cout<<"Did an octal conversion to check answer as well."<<endl;
        cout << "Added 1 to beginning because of float rep. 0001."<<endl;
        cout<<"\t\tANSWER IS: 1.09999990463"<<endl<<endl;
        cout<<"Second:4 6      6 6        6 6       02"<<endl;
        cout<<"0.1000110    01100110   01100110  00000010"<<endl;
        cout<<"Since to the power of 2 it moves over 2 giving me"<<endl;
        cout<<"10.   0011  0011  0011 0011  0011"<<endl;
        cout<<"2.    3     3     3    3     3 HEX with these i convert:"<<endl;
        cout<<"   3x16^-1+  3x16^-2+ 3x16^-3+ 3x16^-4+ 3x16^-5= 0.19999980926"
                <<endl;
        cout<<"Did an octal conversion to check answer as well."<<endl;
        cout << "Added 2 to beginning because of float rep. 0010."<<endl;
        cout<<"\t\tANSWER IS: 2.19999980926"<<endl<<endl;
        cout<<"Third:B 9       9 9        9 A       FE"<<endl;
        cout<<"1.1001001    10011001   10011010   11111110"<<endl;
        cout<<"Since power ^-2 checked by         00000001"<<endl;
        cout<<"Plus 1                                    1"<<endl;
        cout<<"gave me           checked!         00000010"<<endl;
     cout<<"Since i didnt want to work with neg i took pos instead SO:"<<endl;
        cout<<"B 9          9 9        9 A        FE"<<endl;
        cout<<"1.1001001   10011001   10011010   11111110 invert"<<endl;      
        cout<<"0.0110110   01100110   01100101   (ignore)"<<endl;
        cout<<" plus                         1     adding 1"<<endl;
        cout<<"0.0110110   01100110   01100110   "<<endl;
        cout<<"since it was the neg ^-2 power move it over to the left 2"<<endl;
        cout<<"0.00 0110110 01100110   01100110"<<endl;
        cout<<"0.000 1101  1001 1001  1001 1001  1000"<<endl;
        cout<<"0     D     9    9     9    9     8 HEX"<<endl;
     cout<<"0x16^-1+ 13x16^-2+ 9x16^-3+ 9x16^-4+ 9x16^-5+ 9x16^-6+ 8x16^-7\n";
        cout<<"=0.05312499403   now just take the neg of this num"<<endl;
        cout<<"\t\tANSWER IS: -0.05312499403"<<endl<<endl<<endl;
        
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
CustmrChk *Acct(CustmrChk *people, int num, int userChoice)
{
    int numChecks=0;
    int check=0;
    int checkTotal=0;
    int numDeposits=0;
    int deposit=0;
    int depositTotal=0;
    int length;
    //CustmrChk *people1 = new CustmrChk [num];
    //for (int i=0;i < num;i++){
        //people = people;
    //}
    //setting all balance to 0 first
    cout <<"Enter customers account checking number: "<<endl;
                cin >> people[userChoice].acctNum;
                length = people[userChoice].acctNum.size();
                while (length != 5)
                {
                    cout << "Please enter their account number of 5 digits "
                            "only!"<<endl;
                    cin  >> people[userChoice].acctNum;
                    length = people[userChoice].acctNum.size();
                }
                cout <<"Please enter the balance of beginning of month: " 
                        <<endl;
                cin >> people[userChoice].balance;//[num];
                cout <<"Enter amount of checks that were written this month:" ;
                cin >> numChecks;
                while (numChecks < 0){
                        cout << "Enter a positive number for checks!"<<endl;
                        cin >> numChecks;
                }
                if (numChecks > 0){
                    for (int i=0; i<numChecks;i++)
                    {
                        cout <<"Enter Check " <<i+1<<" amount: " ;
                        cin >> check;
                        checkTotal += check;           
                    }
                }
                else
                cout <<"No checks to enter..." <<endl<<endl;
                
                cout <<"Enter amount of deposits that were credited this "
                        "month:" ;
                cin >> numDeposits;
                while (numDeposits < 0){
                        cout << "Enter a positive number for deposits!"<<endl;
                        cin >> numDeposits;
                }
                if (numDeposits > 0){
                    for (int i=0; i<numDeposits;i++)
                    {
                       cout <<"Enter deposit " <<i+1<<" amount: " ;
                       cin >> deposit;
                       depositTotal += deposit;           
                    }
                }
                else
                cout <<"No deposits to enter..." <<endl;
    
                people[userChoice].balance += depositTotal; 
                people[userChoice].balance -= checkTotal;
    
                //output(people, userChoice);
                if (people[userChoice].balance <0){
                    cout<<"Being charged with a $12 dollar overdraft fee."
                              <<endl<<endl;
                    people[userChoice].balance += -12;
                }
                
                cout << "\nAccount balance is: " << people[userChoice].balance
                        <<endl<<endl;
    return people;
    //delete [] people1;
}
void output(CustmrChk *m, int num)
{
    cout << "Customers account is : "<<m[num].acctNum <<endl; 
    cout << "Customers balance :$"<<m[num].balance <<endl<<endl;  
}
void menu (char &c)
{
    cout << "Enter the corresponding actions."  << endl;
    cout << "Enter 1, 2, 3." <<endl;
    cout << "1. To deal with a customer." << endl;
    cout << "2. Output a customers information." << endl;
    cout << "3. Quit!"<< endl;

    cin >> c;
}
void accessCustmr (CustmrChk *m, int &spot, int customers){
    cout << "You have " << customers << " customers. Please choose "
                "one to deal with:"
                <<endl;
                for (int i=0;i<customers;i++)
                {
                   cout <<"Customer " << i+1<< "    press: " <<i+1<<endl;
                }
                cin >>spot;
                while (spot < 1 || spot > customers)
                {
                   cout << "Enter a number 1 thru " << customers<<endl;
                   cin >>spot;
                }
                spot--;
}
Payout *pay(Payout *p, int numEmps){
    
    for(int i=0; i<numEmps;i++){
        cin.ignore();
        cout<<"EMPLOYEE " << i+1<<endl;
        cout <<"Enter employees name: " ;
        getline(cin,p[i].name);
        cout <<"Enter employees rate of pay: ";
        cin >> p[i].payRate;
        while(p[i].payRate < 1){
            cout<<"Enter a number greater than 1: ";
            cin>>p[i].payRate;      
        }
        cout <<"Enter how many hours employee worked: ";
        cin >>p[i].hours;
        while (p[i].hours <0)
        {
            cout<<"enter a number 0 or higher for hours:";
            cin>>p[i].hours;
        }
        
        
        int totalHours = p[i].hours;
        int temp;
        if (totalHours > 40 ){
            temp = p[i].hours - 40;
            //cout <<"triple: " << temp<<endl;
            p[i].pay += (p[i].payRate * 3) * temp;
            totalHours -= temp;
        }
        if (totalHours > 20 ){
            temp = totalHours - 20;
            //cout <<"double: "<< temp <<endl;
            p[i].pay += (p[i].payRate * 2) * temp;
            totalHours -= temp;
        }
        //tripleTime = workers[i].hours % 20;
        //doubleTime = workers[i].hours % 20;
        if (totalHours <= 20 ){
            p[i].pay += p[i].payRate * totalHours;
            //cout <<"single:" <<totalHours<<endl;
        }
        
        
        cout <<endl;
    }
    return p;
}
void output2(Payout *m){
    for(int i=0; i<m->size;i++){
        //for(int j=0; j<4;j++){   
        cout<< "Employees name: " <<m[i].name<<endl;
        cout<< "Employees hours: " <<m[i].hours<<endl;
        cout<< "Employees pay rate: " <<m[i].payRate<<endl;
        cout<< "Employees gets paid: $$" <<m[i].pay << "dollars" <<endl<<endl;
        //}
    }
}
StatsResult *avgMedMode(int *p,int size){
    //working fine now
    //p=fillArray(size,5);
    //int *b=mode(p,size);
    
    int mean1=0, median1=0;
    StatsResult *stats = new StatsResult;
    printArray(p,size,10);
    //printMode(b);
    //int *
    //int *copyPtr = sort(p,size);//copy(p, size);
    mean1 = mean (p, size);
    median1= median (p, size);
    stats->avg= mean1;
    stats->median =median1;
    stats->mode =mode(p,size);
    stats->maxFreq =stats->mode[1];
    stats->nModes=stats->mode[0];
    
    //delete []b;
    //delete []copyPtr;
    
    return stats; 
}
void printstat(StatsResult *s){
    cout << "The mean is: " << s->avg<<endl ;
    cout << "The median is: " << s->median<<endl;
    cout << "The number of modes is: " << s->nModes<<endl;
    cout << "The number of max Frequency is: " << s->maxFreq <<endl;
    //cout<<"WOAAAAAHAAAAAAAAAAAAAAAAAAAA"<<endl;
    printMode(s->mode);
    //cout<<"WOAAAAAHAAAAAAAAAAAAAAAAAAAA"<<endl;
}
void printMode(int *m){
    //Print the mode array
    //cout<<"Number of modes = "<<m[0]<<endl;
    //cout<<"The frequency of the modes = "<<m[1]<<endl;
    if(m[0]==0){
        cout<<"The mode set = {0}"<<endl;
    }else{
        cout<<"The mode set = {";
        for(int i=2;i<m[0]+1;i++){
            cout<<m[i]<<",";
        }
        cout<<m[m[0]+1]<<"}"<<endl;
    }
}

int *sort(int *a,int n){
    //Allocate a sortable array
    int *b=new int[n];
    //Copy the array
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Sort the array
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(b[i]>b[j]){
                b[i]=b[i]^b[j];
                b[j]=b[i]^b[j];
                b[i]=b[i]^b[j];
            }
        }
    }
    return b;
}

int *mode(int *a,int n){
    //Create a parallel array to sort
    int *b=sort(a,n);
    //Count to max frequency
    int count=0,maxFreq=0;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            count++;
            if(maxFreq<count)maxFreq=count;
        }else{
            count=0;
        }
    }
    //cout<<"Max Freq = "<<maxFreq+1<<endl;
    //Count number of modes
    count=0;
    int nmodes=0;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            count++;
            if(maxFreq==count)nmodes++;
        }else{
            count=0;
        }
    }
    //cout<<"Number of Modes = "<<nmodes<<endl;
    //Declare and fill the mode array
    int *mode=new int[nmodes+2];
    mode[0]=nmodes;
    mode[1]=maxFreq+1;
    nmodes=2;
    count=0;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            count++;
            if(maxFreq==count)mode[nmodes++]=b[i];
        }else{
            count=0;
        }
    }
    //Clean up and return
    delete []b;
    return mode;
}

void printArray(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillArray(int n,int mod){
    //Allocate memory
    int *array=new int[n];
    //Initialize with 
    for(int i=0;i<n;i++){
        array[i]=i%mod;
    }
    return array;
}
/*
 * This function takes a list of numbers from an arry/ptr and then calculates
 * the mean of the list of numbers. returns the mean of the numbers
 */
float mean (int *p, int SIZE)
{
    float avg =0;
    float num = 0;
    //loop to go thru numbers
    for (int i=0; i < SIZE; i++)
    {   
        num = p[i];
        avg += num;
    }
    avg = avg/SIZE;
    return avg;
}
/*
 * This function finds the median of elements in a ptr and if the number of
 * elements is even it takes the two middle numbers and divides them, then
 * if odd elements just takes middle num. returns the median.
 */
float median (int *p, int SIZE)
{
    float median = 0;
    int even;
    even = SIZE % 2;
    if (even == 0)
    {
        int num1, num2;
        num1 = p[(SIZE/2)-1];
        num2 = p[(SIZE/2)+1];
        //cout << "NUM1: " <<num1<< " " << "NUM2: " << num2 << " " << endl;
        median = (num1 + num2)/2;
        //cout << "MEDIAN: " << median << " " << endl;
    }
    else 
    {
        int num = p[SIZE/2];
        //cout << "NUM: " << num << " " << endl;
        median = num;
        //cout << "MEDIAN: " << median << " " << endl;
    }
        return median;
}
/*
 * Taking the ascii table and converting it to the actual number.
 */
int realNum (int n){
    int realOne;
    if (n == 48) {
        realOne = 0;
    }
    if (n == 49){
        realOne = 1;
    }if (n == 50) {
        realOne = 2;
    }if (n == 51){
        realOne = 3;
    }if (n == 52){
        realOne = 4;
    }if (n == 53){
        realOne = 5;
    }if (n == 54){
        realOne = 6;
    }if (n == 55){
        realOne = 7;
    }
    return realOne;
}
/*
 * taking each number and dealing with them individually
 */
void encrpyt (int *p, int size){
    for (int i=0; i < size;i++){
        *(p+i) = (p[i]+3)%8;
    }
    /*n = (n+3)%8;
    n1 = (n1+3)%8;
    n2 = (n2+3)%8;
    n3 = (n3+3)%8;*/
    //n %= 8;
    //n1 %= 8;
    //n2 %= 8;
    //n3 %= 8;
    int temp1, temp2;
    temp1 = p[1];
    p[1] = p[0];
    p[0] = temp1;
    temp2 = p[3];
    p[3] = p[2];
    p[2] = temp2;
}
/*
 * decrypt function does the opposite of the encrypt function to get back to 
 * the original integers
 */
void decrpyt (int *p, int size){
    int temp1, temp2;
    temp1 = p[0];
    p[0] = p[1];
    p[1] = temp1;
    temp2 = p[2];
    p[2] = p[3];
    p[3] = temp2;
    for (int i=0; i < size;i++){
        *(p+i) = (p[i]-3+8)%8;
    }
    /*n = (n-3+8)%8;
    n1 = (n1-3+8)%8;
    n2 = (n2-3+8)%8;
    n3 = (n3-3+8)%8;*/
}