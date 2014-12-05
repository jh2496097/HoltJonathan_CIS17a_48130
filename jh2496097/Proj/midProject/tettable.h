/* 
 * File:   tettable.h
 * Author: Jonathan
 *
 * Created on November 20, 2014, 10:20 AM
 */

#ifndef TETTABLE_H
#define	TETTABLE_H
#include "createblock.h"
class TetrisTable{
    private:
        int **table;
        int row;
        int col;
        int **tble ();
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
        int **getTable()const{return table;}
        void placeBlock(int, CreateBlock &, int );
        void outputTable ()const;
};


#endif	/* TETTABLE_H */

