/** 
 * This is the implementation of class TetrisTble
 */


#include "tettable.h"
//constructor
TetrisTable::TetrisTable(){
    table = new int *[row];
    for (int i=0; i<row;i++){
         table[i] = new int [col];
    }
}
TetrisTable::TetrisTable(int r, int c){
    if (r>0)
        row=r;
    if (c>0)
        col=c;
    table = new int *[row];
    for (int i=0; i<row;i++){
         table[i] = new int [col];
    }
}
//copy constructor
TetrisTable::TetrisTable(const TetrisTable &cpyTble){
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
TetrisTable::~TetrisTable(){
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
int **TetrisTable::tble(){
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
void TetrisTable::placeBlock(int spot, CreateBlock &b, int num){
    //column choice of user
    int userChoice = spot-1;
    //int rows = row;
    //bRow = b.getRow();
    //bCol = b.getCol();
    //starting from bottom left to top
    for (int i = row-1; i >= 0; i--){
        for (int k = 0; k < b.getCol(); k++)
        {
           if (table[i][userChoice+k] != 0 )//||
           {
             //setting row
             row = i;
           }            
        }
     }

     for (int i=row-1; i >= row-b.getRow(); i--){
          for(int j=0; j < b.getCol(); j++)  {
              //checking if spot[col] top of table = 1 if so break from placing
              //one
              if (table[0][col] != 0){
                  //breaking from loop cycle
                  break;
              }
              else
               table [i][j+userChoice] = num;                          
          }                
      }
}