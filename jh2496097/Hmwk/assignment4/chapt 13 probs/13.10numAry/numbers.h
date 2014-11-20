/* 
 * File:   numbers.h
 * Author: Jonathan
 *
 * Created on November 1, 2014, 8:31 PM
 */

#ifndef NUMBERS_H
#define	NUMBERS_H

class Numbers{
    private:
        float *nums;
        int size;
        float *fill();
    public:
        //constructors
        Numbers(int);
        //destructors
        ~Numbers();
        //setters
        void storeNum(int,int);
        void setSize(int);
        //getters
        void output() const;
        float getNum(int)const;
        float highest()const;
        float lowest() const;
        float avg()const;
};


#endif	/* NUMBERS_H */

