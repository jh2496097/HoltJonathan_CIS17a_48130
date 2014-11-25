/* 
 * File:   printblock.h
 * Author: Jonathan
 *
 * Created on November 24, 2014, 5:59 PM
 */

#ifndef PRINTBLOCK_H
#define	PRINTBLOCK_H
#include "userobject.h"

class PrintBlock:public UserObject{
    public:
        PrintBlock():UserObject(){}
        void output()const;
};


#endif	/* PRINTBLOCK_H */

