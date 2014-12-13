/* 
 * File:   prob3table.h
 * Author: Jonathan
 *
 * Created on December 8, 2014, 3:03 PM
 */

#ifndef PROB3TABLE_H
#define	PROB3TABLE_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
//template<class T>
class Prob3Table{
	protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		int *rowSum;                                //RowSum array
		int *colSum;                                //ColSum array
		int *table;                                 //Table array
		int grandTotal;                             //Grand total
		void calcTable();                     //Calculate all the sums
	public:
		Prob3Table(string ,int,int);               //Constructor then Destructor
		~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
		const int *getTable(){return table;}
		const int *getRowSum(){return rowSum;}
		const int *getColSum(){return colSum;}
		int getGrandTotal(){return grandTotal;}
};

//template<class T>
Prob3Table::Prob3Table(string name, int r, int c){
    fstream file;
    int num;
    int count=0;
    rows = r;
    cols = c;
    table = new int [r*c];
    file.open(name.c_str());
    if(file){ 
        while(file >> num){
            table[count] = num;
            count++;
        }
    }
    file.close();
    calcTable();
}
//template<class T>
void Prob3Table::calcTable(){
    colSum = new int [cols];
    for (int i=0; i < cols;i++){
        colSum[i] = table[i]+table[i+6]+table[i+12]+table[i+18]+table[i+24];
    }
    rowSum = new int [rows];
    for (int i=0; i < rows;i++){
        rowSum[i] = table[i*6]+table[(i*6+1)]+table[i*6+2]+table[i*6+3]+table[i*6+4]+table[i*6+5];
    }
    
    grandTotal = rowSum[0]+rowSum[1]+rowSum[2]+rowSum[3]+rowSum[4];
}
#endif	/* PROB3TABLE_H */

