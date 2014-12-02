/* 
 * File:   block.h
 * Author: Jonathan
 *
 * Created on November 30, 2014, 8:47 PM
 */

#ifndef BLOCK_H
#define	BLOCK_H

class Block{
    private:
        int row;
        int col;
    public:
        class BadRow{};
        class BadCol{};
        Block ();
        Block (int, int);
        void setRow (int);
        void setCol (int);
        int getRow()const{return row;}
        int getCol()const{return col;}
};

#endif	/* BLOCK_H */

