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
    public:
        UserObject();
        UserObject(int, int);
        ~UserObject();
        void setRow(int);
        void setCol(int);
        int getRow()const;
        int getCol()const;
};

#endif	/* USEROBJECT_H */

