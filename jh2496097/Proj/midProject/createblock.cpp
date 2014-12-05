///implementation of create block class derived from block class

#include "createblock.h"
#include <iostream>
using namespace std;
CreateBlock::CreateBlock(){
    ///setting dimensions to 1x1
    setRow (1);
    setCol (1);
    ///dynamically allocating memory
    block = new int *[getRow()];
    for (int i=0; i < getRow();i++){
        block[i] = new int [getCol()];
    }
    fillBlock();
}
CreateBlock::CreateBlock(int r, int c):Block(r, c){
    block = new int *[r];
    for (int i=0; i < r;i++){
        block[i] = new int [c];
    }
    fillBlock();
}
/**
 * Filling object with 1's 
 */
void CreateBlock::fillBlock(){
    for(int i =0; i < getRow();i++){
        for (int j =0; j<getCol(); j++){
            block[i][j] = 1; 
        }
    }
}
/**
 * Destructor
 * destroy class 2D pointer is used to delete all of the dynamically created 
 * objects in the class  so need to delete by rows first then delete
 * the entire thing.
 */
CreateBlock::~CreateBlock(){
    //cout << "CALLING DESTRUCTOR"<<endl;
    for(int i=0;i<getRow();i++)
    {
        delete []block[i];
    }
    delete []block;
}
void CreateBlock::makeBlock(){
    block = new int *[getRow()];
    for (int i=0; i <getRow();i++){
        block[i] = new int[getCol()];
    }
    fillBlock();
}
//polymoyphism
void CreateBlock::print(Block &b) {
    int count=0;
    cout << "\tThis is your block : " << endl;
        for (int i=0; i <b.getRow(); i++){//rows
            cout << "\t";
           for(int j=0; j <b.getCol(); j++){//cols
              block[i][j]= 1;
              cout << block[i][j]  << "  ";
              count++;
              if (count == b.getCol())
              {
                  cout <<  endl;
                  count = 0;
              }
           } 
        }
}