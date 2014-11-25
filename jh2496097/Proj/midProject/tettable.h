/* 
 * File:   tettable.h
 * Author: Jonathan
 *
 * Created on November 20, 2014, 10:20 AM
 */

#ifndef TETTABLE_H
#define	TETTABLE_H

class TetrisTable{
    private:
        int **table;
        int row;
        int col;
        int **tble ();
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
        void placeBlock(int, int);
};


#endif	/* TETTABLE_H */

