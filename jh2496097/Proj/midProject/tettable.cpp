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