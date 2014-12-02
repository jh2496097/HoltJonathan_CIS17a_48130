/* 
 * File:   productionworker.h
 * Author: Jonathan
 *
 * Created on November 25, 2014, 10:30 AM
 */

#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H

#include "employee.h"

class ProductionWorker : public Employee{
    private:
        int shift;
        float hourly;
    public:
        class WrongInput{};
        ProductionWorker();
        ProductionWorker(int, float);
        ProductionWorker(int, float, string, string, string);
        void setShift (int);
        void setHourly (float);
        int getShift ()const {return shift;}
        float getHourly ()const {return hourly;}           
};

#endif	/* PRODUCTIONWORKER_H */

