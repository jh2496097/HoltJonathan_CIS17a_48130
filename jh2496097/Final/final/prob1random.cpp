//implementation of prob1rand
#include "prob1random.h"
#include <cstdlib>

Prob1Random::Prob1Random(const char n , const unsigned char *s){
    //srand(time(NULL));
    nset = n;
    numRand =0;
    freq = new int [nset];
    for(int i=0;i<n;i++)
        freq[i]=0;
    set = new unsigned char [nset];
    for (int i=0; i < n;i++){
        set[i] = s[i];
    }
}
Prob1Random::~Prob1Random(){
    delete []set;
    delete []freq;
}
char Prob1Random::randFromSet(){
    int num =  rand()%5;
    if (num == 0)
        freq[0]++;
    if (num == 1)
        freq[1]++;
    if (num == 2)
        freq[2]++;
    if (num == 3)
        freq[3]++;
    if (num == 4)
        freq[4]++;
    
    numRand++;
}