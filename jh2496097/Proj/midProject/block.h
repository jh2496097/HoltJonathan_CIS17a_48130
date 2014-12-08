/* 
 * File:   block.h
 * Author: Jonathan
 *
 * Created on November 30, 2014, 8:47 PM
 */

#ifndef BLOCK_H
#define	BLOCK_H
#include "absblock.h"
class Block: public AbsBlock{
    private:
        int row;
        int col;
    public:
        //exceptions
        class BadRow{};
        class BadCol{};
        Block ();
        Block (int, int);
        void setRow (int);
        void setCol (int);
        int getRow(){return row;}
        int getCol(){return col;}
};

#endif	/* BLOCK_H */

