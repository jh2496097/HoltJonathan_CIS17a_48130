/* 
 * File:   prob3tableinherit.h
 * Author: Jonathan
 *
 * Created on December 8, 2014, 3:04 PM
 */

#ifndef PROB3TABLEINHERIT_H
#define	PROB3TABLEINHERIT_H
#include "prob3table.h"
//template<class T>
class Prob3TableInherited:public Prob3Table{
	protected:
		int *augTable;                         //Augmented Table with sums
	public:
		Prob3TableInherited(string,int,int);          //Constructor
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const int *getAugTable(){return augTable;}; 
};

//template<class T>
Prob3TableInherited::Prob3TableInherited(string n, int r, int c):Prob3Table(n,r,c){
    
    rows = r +1;
    cols = c +1;
    int rowCount=0;
    int colCount=0;
    augTable = new int [rows*cols];
    for(int i=0;i<(rows);i++)
    {
        augTable[i] = table[i];
        augTable[rows] = rowSum[0];
        /*if (i == 6 ||i == 13 ||i == 20 ||i == 27 ||i == 34){
            augTable[i] = rowSum[rowCount++];
            table[i]--;
        }
        else if (i == 35 ||i == 36 ||i == 37 ||i == 38 ||i == 39||i == 40)
            augTable[i] = colSum[colCount++];
        else
            augTable[i] = table[i];*///values getting replaced does not work
    }
    for(int i=rows+1;i<=(rows*2);i++)
    {
        augTable[i] = table[i-1];
        augTable[rows*2+1] = rowSum[1];
    }
    for(int i=rows*2+2;i<=(rows*3+1);i++)
    {
        augTable[i] = table[i-2];
        augTable[rows*3+2] = rowSum[2];
    }
    for(int i=rows*3+3;i<=(rows*4+2);i++)
    {
        augTable[i] = table[i-3];
        augTable[rows*4+3] = rowSum[3];
    }
    for(int i=rows*4+4;i<=(rows*5+3);i++)
    {
        augTable[i] = table[i-4];
        augTable[rows*5+4] = rowSum[4];
    }
    for (int i = 36-1; i <= 40;i++ ){
        augTable[i] = colSum[i-35];
    }
    augTable[rows*cols-1] = grandTotal;
}
#endif	/* PROB3TABLEINHERIT_H */

