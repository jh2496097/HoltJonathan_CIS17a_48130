/* 
 * File:   prob2sort.h
 * Author: Jonathan
 *
 * Created on December 8, 2014, 2:49 PM
 */

#ifndef PROB2SORT_H
#define	PROB2SORT_H
#include <cstdlib>
#include <iostream>
//template <class T>
class Prob2Sort
{
	private:
		int *index;                                 //Index that is utilized in the sort
	public:
		Prob2Sort(){index=NULL;};                   //Constructor
		~Prob2Sort(){delete []index;};              //Destructor
		int *sortArray(const char*,int,bool);           //Sorts a single column array
		int *sortArray(const char*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
}; 

int *Prob2Sort::sortArray(const char* tble, int row, int col, int col_num, bool up){
   // for (int i =0; i < row;i++){
        //tble[i*17+col_num]
    //}
    //bool swap;
    //string temp;
    /*do
    {
        up = false;
        for (int i = 0; i < row; i++)
        {
            if(tble[i*17+col_num] >tble[i*17+col_num+1])
            {
                temp = tble[i];
                tble[i]=tble[i+1];
                tble[i+1] = temp;
                swap = true;
            }
        }
    }while (up);*/
}
#endif	/* PROB2SORT_H */

