/** 
 * This is the implementation of class PrintTable
 */
#include "printblock.h"
#include <iostream>
using namespace std;

void PrintBlock::output() const{
    int count=0;
    cout << "\tThis is your block : " << endl;
        for (int i=0; i <getRow(); i++){//rows
            cout << "\t";
           for(int j=0; j <getCol(); j++){//cols
              //object[i][j]= 1;
              //cout << object[i][j]  << "  ";
              count++;
              if (count == getCol())
              {
                  cout <<  endl;
                  count = 0;
              }
           } 
        }
}