/**
 * Jonathan Holt
 * numbers cpp file
 */
#include "numbers.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
Numbers::Numbers(int s){
    if (s < 1)
        s = 1;
    else
        size =s;
    nums = fill();
}
Numbers::~Numbers(){
    delete []nums;
}
float *Numbers::fill(){
    nums = new float [size];
    srand(time(NULL));
    for (int i=0; i<size;i++){
        nums[i] = rand()%90+10;
    }
    return nums;
}
void Numbers::storeNum(int spot, int num){
    if(spot>=0&&spot< size)
        nums[spot] = num;
}
void Numbers::setSize(int num){
    if (size < 1)
        size =1;
    else 
        size = num;
}
void Numbers::output() const{
    int skip=0;
    for (int i=0; i<size;i++){
        cout << nums[i] << "  ";
        skip++;
        if (skip==8){
            skip=0;
            cout << endl;
        }
    }
    cout <<endl;
}
float Numbers::getNum(int spot) const{
    if (spot>=0&&spot< size)
        return nums[spot];
    else
        return 0;
}
float Numbers::highest() const{
    int high = nums[0];
    for (int i=1;i<size;i++){
        if(nums[i] > high)
        {
            high = nums[i];
        }
    }
    return high;
}
float Numbers::lowest() const{
    int low = 1000;
    for (int i=0;i<size;i++)
    {
        if (nums[i] < low){
            low = nums[i];
        }
    }
    return low;
}
float Numbers::avg() const{
    //sorting
    float avg;
    float tot;
    /*for (int i=0; i<size;i++){
        for(int j=i; j< size;j++){
            if (nums[i] > nums[j]){
                float temp=nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }*/
    for (int i=0; i <size;i++){
        tot += nums[i];
    }
    
    return tot/size;
}