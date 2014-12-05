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
        int **block;
        void fillBlock();
    public:
        CreateBlock();
        CreateBlock (int,int); 
        ~CreateBlock();
        void makeBlock();
        void print(Block &);
        int **getBlock()const {return block;};
};

#endif	/* CREATEBLOCK_H */