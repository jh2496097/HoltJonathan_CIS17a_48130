/* 
 * File:   tettable.h
 * Author: Jonathan
 *
 * Created on November 20, 2014, 10:20 AM
 */

#ifndef TETTABLE_H
#define	TETTABLE_H
#include "createblock.h"
#include "tettable.h"
#include <string>
#include <iostream>
using namespace std;

template<class T>
class TetrisTable{
    private:
        int **table;
        int row;
        int col;
        T points;
        int **fill_tble ();
        CreateBlock b;
    public:
        //constructors
        TetrisTable();
        TetrisTable(int, int);
        //copy constructor
        TetrisTable (const TetrisTable &);
        //destructor
        ~TetrisTable();       
        //getters
        int getRow()const{return row;}
        int getCol()const{return col;}
        int getPoints()const{return points;}
        int **getTable()const{return table;}
        int getElem(int i, int j){return table[i][j];}
        //if(i>=0&&i<size)
           
        void placeBlock(int, CreateBlock &, int );
        void outputTable ()const;
        void newTable();
        bool game();
};

//constructor
template<class T>
TetrisTable<T>::TetrisTable(){
    table = new int *[row];
    for (int i=0; i<row;i++){
         table[i] = new int [col];
    }
    points =0;
}
template<class T>
TetrisTable<T>::TetrisTable(int r, int c){
    //get an execption in here
    if (r>0)
        row=r;
    if (c>0)
        col=c;
    table = new int *[row];
    for (int i=0; i<row;i++){
         table[i] = new int [col];
    }
    table = fill_tble();
    points =0;
}
//copy constructor
template<class T>
TetrisTable<T>::TetrisTable(const TetrisTable &cpyTble){
    row = cpyTble.row;
    col = cpyTble.col;
    table = new int *[row];
    //allocate
    for(int i=0;i<row;i++){
        table[i]=new int [col];
    }
    //copy contents 
    for(int i=0;i <row;i++){
        for(int j=0;j<col;j++){
            table[i][j] = cpyTble.table[i][j];
        }
    }
}
/**
 * destroy class 2D pointer is used to delete all of the dynamically created 
 * objects in the class  so need to delete by rows first then delete
 * the entire thing.
 */
template<class T>
TetrisTable<T>::~TetrisTable(){
    for(int i=0;i<row;i++)
    {
        delete []table[i];
    }
    delete []table;
}
/**
 * Function creates a dynamic two dimensional table which is created by the
 * size of ROWS and COLS and sets all elements to 0. After that it then returns
 * the 2D pointer filled with 0s.
 * @return 2D dynamic pointer.
 */
template<class T>
int **TetrisTable<T>::fill_tble(){
    table = new int *[row];
    for (int i=0;i<row;i++){
        table[i] = new int [col];
    }
    /**< Filling the Table. */
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            table[i][j] = 0;
        }
    }
    return table;
}
/**
 * The function objtPlcmnt is first going take 2D table then since object is
 * of a certain size looking at size of column spots to check for a #. If there
 * is a # in either spot i set rows to that spot to then place object on top 
 * of the numbers in table. Uses a break statement to break from going over
 * bounds when placing an object.
 * @param spot user picked spot of user
 * @param b aggregation of a class to use placement of block
 * @param num number represented with block
 */
template<class T>
void TetrisTable<T>::placeBlock(int spot, CreateBlock &b, int num){
    //column choice of user
    int userChoice = spot-1;
    int rowStart;
    //bRow = b.getRow();
    //bCol = b.getCol();
    //starting from bottom left to top
    for (int i = row-1; i >= 0; i--){
        for (int k = 0; k < b.getCol(); k++)
        {
           if (table[i][userChoice+k] != 0 )//||
           {
             //setting row
             rowStart = i;
           }            
        }
     }

     for (int i=rowStart-1; i >= rowStart-b.getRow(); i--){
          for(int j=0; j < b.getCol(); j++)  {
              //checking if spot[col] top of table = 1 if so break from placing
              //one
              if (table[0][userChoice] != 0){
                  //breaking from loop cycle
                  break;
              }
              else
                  table[i][j+userChoice] = num;                          
          }                
      }
}
/**
 * This function is used to output the 2D table to the console that user will
 * be interacting with by placing objects in it. Outputs this table constantly
 * so user can always see it.
 * @param ptr 2D pointer.
 * @param rows size for rows.
 * @param cols size for columns.
 */
template<class T>
void TetrisTable<T>::outputTable() const{
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        cout << "\t\t";
        for(int j = 0; j < col; j++)
        {
            cout << table[i][j] << "   ";
            count++;
            if (count == col)
            {
                cout << endl;
                count = 0; 
            }
        }
    }
    cout << "\t    -------------------------------------" << endl;
    cout << "Columns \t1   2   3   4   5   6   7   8     "<< endl<<endl;
}
template<class T>
void TetrisTable<T>::newTable(){
    int dstryRow=0; /**< Integer value of row where replacing happens.*/ 
    int count=0;/**< Integer value of number of rows filled at a time.*/ 
    for (int i = 0; i < row; i++) {
            if (table[i][0] != 0 && table[i][1] != 0 &&
                    table[i][2] != 0 && table[i][3] != 0 &&
                    table[i][4] != 0 && table[i][5] != 0 &&
                    table[i][6] != 0 && table[i][7] != 0)
            {
                count++;
            }
    }
    cout << "YOU GOT* " << count << " ROWS AT ONCE."<<endl;
    
        for (int i = 0; i < row; i++)
        {
            if (table[i][0] != 0 && table[i][1] != 0 &&table[i][2] != 0 &&
                    table[i][3] != 0 &&table[i][4] != 0 &&table[i][5] != 0 &&
                    table[i][6] != 0 &&table[i][7] != 0)
            {          
                points += 10*count;
                dstryRow=i;
                /**
                 * Had to create table in loop or else same table was getting
                 * copied this way new table gets copied with deleted row.
                 */
                int **newTble= new int *[row];;/**< Creating new table to copy.*/
                for (int i=0;i<row;i++){
                     newTble[i] = new int [col];
                }
                for (int i =0; i < row; i++){
                    for (int j =0; j < col; j++){
                        newTble[i][j] = getElem(i,j); /**< Copying contents.*/
                    }
                }
                for (int i =0; i < row; i++){
                    for (int j =0; j < col; j++){
                        cout << newTble[i][j] <<" ";
                    }
                    cout <<endl;
                }
                cout <<endl;
                //setting row above to = to the row to be deleted
                for (int k = 0; k < dstryRow; k++){
                     for (int j =0; j < col ; j++){
                          table[k+1][j] = newTble[k][j];
                     }
                }       
            }          
        }  
}
/**
 * The function isOver is checking for a non 0 value on the first row of the 
 * table. If it finds this value it instantly breaks from stacking objects on
 * the table that way over bounds issues will not come into play.
 */
template<class T>
bool TetrisTable<T>::game(){
    bool lose;
    for (int j=0; j < col;j++){
        if (table[0][j] != 0)
        {
            lose = false;
            break;
        }
        else
            lose = true;
    }
    return lose;
}
#endif	/* TETTABLE_H */

