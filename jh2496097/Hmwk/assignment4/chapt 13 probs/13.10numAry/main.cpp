/* 
 * Jonathan Holt
 * C++ objects
 * assignment 4
 * i certify this is my work
 * Created on November 1, 2014, 8:30 PM
 */

#include <cstdlib>
#include <iostream>
#include "numbers.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int size = 48;
    Numbers n(size);
    float highest;
    float lowest;
    float area;
    float avg;
    n.output();
    highest = n.highest();
    area = n.getNum(49);
    lowest = n.lowest();
    avg = n.avg();
    cout <<"HIGHEST: " << highest << endl;
    cout <<"LOWEST: " << lowest << endl;
    cout <<"SPOT(49): " << area << endl;
    cout <<"AVERAGE: " << avg <<endl;
    n.output();

    return 0;
}

