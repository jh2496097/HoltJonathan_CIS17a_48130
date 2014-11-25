/** 
 * This is the implementation of class UserOBject
 */

#include "userobject.h"
#include <iostream>
using namespace std;
//constructors
UserObject::UserObject(){
    row = 1;
    col = 1;
    object = new int *[row];
    for (int i=0; i <row;i++){
        object[i] = new int[col];
    }
    fillObject();
}
UserObject::UserObject(int r, int c){
    col = c;
    row = r;
    object = new int *[row];
    for (int i=0; i <row;i++){
        object[i] = new int[col];
    }
    fillObject();
}
/**
 * Filling object with 1's 
 */
void UserObject::fillObject(){
    for(int i =0; i < row;i++){
        for (int j =0; j<col; j++){
            object[i][j] = 1; 
        }
    }
}
/**
 * Destructor
 * destroy class 2D pointer is used to delete all of the dynamically created 
 * objects in the class  so need to delete by rows first then delete
 * the entire thing.
 */
UserObject::~UserObject(){
    cout << "CALLING DESTRUCTOR"<<endl;
    for(int i=0;i<row;i++)
    {
        delete []object[i];
    }
    delete []object;
}
void UserObject::createBlk(){
    object = new int *[row];
    for (int i=0; i <row;i++){
        object[i] = new int[col];
    }
    fillObject();
}
int UserObject::getCol() const{
    return col;
}
int UserObject::getRow() const{
    return row;
}
void UserObject::setCol(int c){
    col = c;
}
void UserObject::setRow(int r){
    row  = r; 
}
void UserObject::print() const{
    int count=0;
    cout << "\tThis is your block : " << endl;
        for (int i=0; i <row; i++){//rows
            cout << "\t";
           for(int j=0; j <col; j++){//cols
              object[i][j]= 1;
              cout << object[i][j]  << "  ";
              count++;
              if (count == col)
              {
                  cout <<  endl;
                  count = 0;
              }
           } 
        }
}
int **UserObject::getBlock()const{
    return object;
}
