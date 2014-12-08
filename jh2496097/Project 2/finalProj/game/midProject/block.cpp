///implementation of block class

#include "block.h"

Block::Block(){
    row = 1;
    col = 1;
}
Block::Block(int r, int c){
    if (r < 1)
        throw BadRow();
    else
        row = r;
    if (c < 1)
        throw BadCol();
    else
        col = c;
}
void Block::setRow(int r){
    if (r < 1)
        throw BadRow();
    else
        row = r;
}
void Block::setCol(int c){
    if (c < 1)
        throw BadCol();
    else
        col = c;
}