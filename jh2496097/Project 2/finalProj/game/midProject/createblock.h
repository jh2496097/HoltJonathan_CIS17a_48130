/* 
 * File:   createblock.h
 * Author: Jonathan
 *
 * Created on November 30, 2014, 9:15 PM
 */

#ifndef CREATEBLOCK_H
#define	CREATEBLOCK_H

#include "block.h"
//Derived class from block
class CreateBlock : public Block{
    private:
        int **block;/**< 2D ptr that user will be prompted with.*/
        void fillBlock();
        int num;
    public:
        CreateBlock();
        CreateBlock (int,int); 
        ~CreateBlock();
        void rotateBlock(Block &);
        void makeBlock();
        void print(Block &,int);
        int **getBlock()const {return block;};
};

#endif	/* CREATEBLOCK_H */