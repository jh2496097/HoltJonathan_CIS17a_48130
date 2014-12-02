//implementation of production worker class

#include "productionworker.h"
#include <string>
using namespace std;

ProductionWorker::ProductionWorker(){
    shift = 0;
    hourly = 0.0;
}
ProductionWorker::ProductionWorker(int s, float h){
    if (s>=1&&s<=2)
        shift = s;
    else 
        throw WrongInput{};
    if (h > 0)
        hourly = h;
    else 
        throw WrongInput{};
}
ProductionWorker::ProductionWorker(int s, float h, string n, string e, 
        string hire)
{
    if (s>=1&&s<=2)
        shift = s;
    else 
        throw WrongInput{};
    
    if (h > 0)
        hourly = h;
    else 
        throw WrongInput{};
    setName(n);
    setEmpNum(e);
    setHire(hire);
}
void ProductionWorker::setHourly(float h){
    if (h > 0)
        hourly = h;
    else 
        throw WrongInput{};
}
void ProductionWorker::setShift(int s){
    if (s>=1&&s<=2)
        shift = s;
    else 
        throw WrongInput{};
}