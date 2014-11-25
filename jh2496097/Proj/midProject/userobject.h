/* 
 * File:   userobject.h
 * Author: Jonathan
 *
 * Created on November 22, 2014, 7:06 PM
 */

#ifndef USEROBJECT_H
#define	USEROBJECT_H

class UserObject{
    private:      
        int **object;
        int row;
        int col;
        void fillObject();
    public:   
        UserObject();
        UserObject(int, int);
        ~UserObject();
        void createBlk();
        void setRow(int);
        void setCol(int);
        int getRow()const;
        int getCol()const;
        int **getBlock()const;
        //int **getPointr(**int);
        void print()const;       
};

#endif	/* USEROBJECT_H */

