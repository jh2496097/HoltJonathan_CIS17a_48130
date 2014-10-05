/*
 * Jonathan Holt
 * C++ objects
 * i certify this is my work
 * Created on October 4, 2014, 9:27 PM
 * 
 * Assignment 2
 */

#include <cstdlib>
#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;
//structure for corporation
struct CorpSales
{
    string area;
    float sales1;
    float sales2;
    float sales3;
    float sales4;
};
//prob2
void prob2();
///prob4
void prob4();
//prob5
void prob5 ();
//prob8
void arraytoFile (fstream &, int *, int);
void filetoArray (fstream &, int *, int);
int *filAry (int *, int);
void outputAry (int *, int);
void prob8();
//prob11
void prob11();
void createSpace();
int main(int argc, char** argv) {

    //choice to end do while
    char choice;
    do
    {
        //choice for problems
        char probChoice;
        
        cout << "This is a list of chapter 12 problems." << endl;
        cout << "Choose between the numbers 1 to 5" << endl;
        cout << "1. Chptr12 number 2 File displayer" << endl;
        cout << "2. Chptr12 number 4 last 10 lines of file" << endl;
        cout << "3. Chptr12 number 5 file line shower" << endl;
        cout << "4. Chptr12 number 8 arry to File/File to arry (Works " << 
                "inproperly)" << endl;
        cout << "5. Chptr12 number 11 corporation input/output (outputs " << 
                "incorrectly)" << endl;
        cin >> probChoice;
        
        switch (probChoice)
                {
                case '1': 
                    createSpace();
                    prob2();
                break;
                case '2': 
                    createSpace();
                    prob4();
                break;
                case '3': 
                    createSpace();
                    prob5 ();
                break;
                case '4': 
                    createSpace();
                    prob8();
                break;
                case '5': 
                   createSpace();
                   prob11();
                break;
            
            default: cout << "You entered a wrong choice\n";
            createSpace();
        }
        createSpace();
        cout << "Do you wish to pick another program enter anything else " << 
                endl << "besides 'q' or 'Q': " << endl;
        cin >> choice;
    }while(toupper(choice) != 'Q');
    
    return 0;
}
/*
 * creates space for easier reading
 */
void createSpace()
{
    for (int i=0 ; i < 4; i++)
    {
        cout << endl;
    }
}
/*
 * This function is from gaddis 8th edition number 2 it displays a file
 * contents to the 24 line and then ask user to strike a key to continue reading
 * the file by every 24 lines.
 */
void prob2()
{
    string fileName;
    fstream file;
    string fileRead;
    int count =0;
    char stopper;
    
    cout << "This program reads the tail end of a file." << endl;
    cout << "This file name is called lines.txt" << endl;
    cout << "Enter the name of the file you wish to open." << endl;
    cin >> fileName;
    file.open(fileName.c_str(), ios::in);
    if (file.fail())
    {
        cout << "The file you entered does not exist." << endl;
        cout << "PLease recreate file and store multiple lines into it.\n";
    }
    else
    {
        cout << "Reading the file..." << endl;
        if(file)
        {
            //cin.ignore();
            getline(file, fileRead);
            while (file)
            {
                cout << fileRead << endl;
                count++;
                //cin.ignore();
                getline(file, fileRead);
                if (count == 24)
                {
                   cin.ignore();
                   cout << "Press enter or anything to view next 24 lines:" 
                           << endl;
                   cin.get(stopper);
                   count = 0;
                }
            }
        }
    }
    cout << "That is everything in the file!!!" << endl;
    file.close();
}
/*
 * This program is from gaddis ed 8th number 4 and it takes a file and only 
 * prints the last 10 lines of the file if it is shorter than 10 lines 
 * outputs that and still shows contents. Uses a counter to count lines and 
 * then finds the max line and prints of last 10.
 */
void prob4()
{
    string fileName;
    fstream file;
    string fileRead;
    int count = 0;
    int max;
    const int TENLINES = 10;
    cout << "This program reads the tail end of a file." << endl;
    cout << "This file name is called text.txt" << endl;
    cout << "If the file is shorter than 10 lines outputs it is and prints "
            "lines"<< endl;
    cout << "Enter the name of the file you wish to open." << endl;
    cin >> fileName;
    file.open(fileName.c_str(), ios::in);
    if (file.fail())
    {
        cout << "This file you entered does not exist." << endl;
    }
    else
    {
        cout << "Reading the file..." << endl;
        if(file)
        {
            getline(file, fileRead);
            while (file)
            {
                //cout << fileRead << endl;
                count++;
                getline(file, fileRead);              
            }
        }
        //getting amount of lines that were read
        max = count;
        //cout << "Max : " << max << endl;
        file.close();
        file.open(fileName.c_str(), ios::in);
        if (max <= 10)
        {
            cout << "Full file is displayed less than or equal to 10 lines"
                      <<endl;
            while(!file.eof())
            {
                getline(file, fileRead);
                while (file)
                {
                     cout << fileRead << endl;
                     //count++;
                     getline(file, fileRead);
                }
            }
        }
        file.close();
        file.open(fileName.c_str(), ios::in);
        if (max > 10)
        {
            count = 0;
            cout << "Printing tail end of file of 10 lines.." <<endl;
            if(file)
            {
                getline(file, fileRead);
                while (file)
                {
                     //cout << fileRead << endl;
                     count++;
                     if (count > (max - TENLINES))
                     {
                        cout << fileRead << endl;
                        //getline(file, fileRead);
                        //count++;
                     }
                     getline(file, fileRead);
                }
            }
        }
    }
    //cout <<"the count is: " << count << endl;
    file.close();
}
/*
 * this problem is from gaddis 8th ed and it outputs the contents of the file
 * to the screen by also providing a line count to the user. This problem is 
 * almost exactly like number 2.
 */
void prob5 ()
{
    string fileName;
    fstream file;
    string fileRead;
    int lineCount =0;
    int count =0;
    char stopper;
    
    cout << "This program reads the tail end of a file. " << endl;
    cout << "This file name is called text1.txt" << endl;
    cout << "Enter the name of the file you wish to open." << endl;
    cin >> fileName;
    file.open(fileName.c_str(), ios::in);
    if (file.fail())
    {
        cout << "The file you entered does not exist." << endl;
        cout << "PLease recreate file and store multiple lines into it.\n";
    }
    else
    {
        cout << "Reading the file..." << endl;
        if(file)
        {
            //cin.ignore();
            getline(file, fileRead);
            while (file)
            {
                lineCount++;
                cout << lineCount << ":"<< fileRead << endl;
                count++;
                //cin.ignore();
                getline(file, fileRead);
                if (count == 24)
                {
                   cin.ignore();
                   cout << "Press enter or anything to view next 24 lines:" 
                           << endl;
                   cin.get(stopper);
                   count = 0;
                }
            }
        }
    }
    cout << "\n\nThat is everything in the file!!!" << endl;
    file.close();
}
/*
 * Fills an array with the index number till the size of the array
 * returns filled array
 */
int *filAry (int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(a + i) = i+10;
    }
    return a;
}
/*
 * Outputs a single dimensional array till it reaches its size
 * returns nothing
 */
void outputAry (int *a, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        cout << *(a + i) << "    " ;
        count++;
        if (count == 8)
        {
            cout << endl;
            count =0;
        }
    }
    cout << endl;
}
/*
 * writing an array to a file with binary 
 */
void arraytoFile (fstream &file, int *a, int size)
{
    cout << "Writing to the file..." << endl;
    file.write(reinterpret_cast<char *>(a), sizeof(a));
}
/*
 * reading from a binary file and storing into an array
 */
void filetoArray (fstream &file, int *a, int size)
{
    cout << "Reading from the file..." << endl;
    file.read(reinterpret_cast<char *>(a), sizeof(a));
}
void prob8()
{
    cout << "This is a program that sends contents of an array to a " << endl
            << "file. Then takes that information and stores it into an array."
            << endl;
    cout << "\n[[[[[This program may work but doesn't work in the correct way" << endl
            << "getting info from file doesn't seem to work when storing to"
            " an array.]]]]]\n" << endl;
    fstream file  ;

    const int SIZE = 25;
    int *ary = new int [SIZE];
    int *ary2 = new int [SIZE];
    //filling array with a index counter
    ary = filAry (ary, SIZE);
    //outputAry (ary, SIZE);
    file.open ("ints.txt", ios::out | ios::in | ios::binary);
    
    arraytoFile (file, ary, SIZE);
    filetoArray (file, ary, SIZE);
    
    file.close();
    //calling to output to file
    //arraytoFile (file, ary, SIZE);
    //outputAry (ary, SIZE);
    //calling to read from file
    //ary2 = filetoArray (file, ary, SIZE);
    
    outputAry (ary, SIZE);
    
    delete [] ary;
    delete [] ary2;
}
/*
 * This program gets the sales from a coporation desired by user
 * i have it set up for quaker and it gets the area then the quarterly sales
 * from a structure.
 * Takes the info and puts it into a file then read the info back (when reading
 * back area is displayed incorrectly)
 */
void prob11()
{
    CorpSales quaker;
    fstream data("quaker.dat",  ios::out | ios::binary);
    char choice;
    
    cout <<"This program lets you input the sales of the Quaker corporation"
            "!!!" << endl;
    cout << "FOR SOME REASON AREA IS REPRINTED..." << endl;
    do
    {
        cout << "Enter the area in which sales are coming in\n"
                << "(I.E. West, South, East, North): " << endl;
        cin.ignore();
        cin >> quaker.area;
            cout << "Enter the sales for 4 quarters \n(I.E. 1330.54): " << 
                    endl ;
        cout << "Quarter 1: $";
        cin >> quaker.sales1;
            while (quaker.sales1 < 0)
            {
                cout << "Enter a POSTIVE number for sales: ";
                cin >> quaker.sales1;
            }
        cout << "Quarter 2: $";
        cin >> quaker.sales2;
            while (quaker.sales2 < 0)
            {
                cout << "Enter a POSTIVE number for sales: ";
                cin >> quaker.sales2;
            }
        cout << "Quarter 3: $";
        cin >> quaker.sales3;
            while (quaker.sales3 < 0)
            {
                cout << "Enter a POSTIVE number for sales: ";
                cin >> quaker.sales3;
            }
        cout << "Quarter 4: $";
        cin >> quaker.sales4;
            while (quaker.sales4 < 0)
            {
                cout << "Enter a POSTIVE number for sales: ";
                cin >> quaker.sales4;
            } 
        
        data.write(reinterpret_cast<char *>(&quaker), sizeof(quaker));
        
        
        cout << "Do you want to enter more information about the corporation"
                << endl << "enter 'y' or anything else to stop:" << endl;
        //cin.ignore();
        cin >> choice;
        
    }while (choice== 'Y' || choice == 'y');
    
    /*
     * Now reading from file
     */
    data.close();
    data.open("quaker.dat", ios::in | ios::binary);
    cout << "\n\nHere is the Sale information about Quaker\n";
    data.read(reinterpret_cast<char *>(&quaker), sizeof(quaker));
    while (!data.eof())
    {
        cout << "Area: ";
        cout << quaker.area << endl;
        cout << "Sales..." << endl;
        cout << "Quarter 1: $";
        cout << quaker.sales1;       
        cout << "\nQuarter 2: $";
        cout << quaker.sales2;           
        cout << "\nQuarter 3: $";
        cout << quaker.sales3;
        cout << "\nQuarter 4: $";
        cout << quaker.sales4;
     
        cout << "\n\nPress the enter key to see next set of data." << endl;
        cin.ignore();
        cin.get(choice);
        
        //rereading
        data.read(reinterpret_cast<char *>(&quaker), sizeof(quaker));
    }
    cout << "Thats all the data in the file." << endl << endl; 
    data.close();
}