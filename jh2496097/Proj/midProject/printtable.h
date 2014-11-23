/* 
 * File:   printtable.h
 * Author: Jonathan
 *
 * Created on November 22, 2014, 6:39 PM
 */

#ifndef PRINTTABLE_H
#define	PRINTTABLE_H

#include "tettable.h"

class PrintTable:public TetrisTable{
    private:
    public:
        PrintTable(int r, int c):TetrisTable(r, c){};
        void output (int r, int c);
};


#endif	/* PRINTTABLE_H */

