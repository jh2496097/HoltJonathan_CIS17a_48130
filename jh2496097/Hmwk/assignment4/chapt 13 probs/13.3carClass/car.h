/* 
 * File:   car.h
 * Author: Jonathan
 *
 * Created on November 1, 2014, 5:40 PM
 */

#ifndef CAR_H
#define	CAR_H
#include <string>
using namespace std;
class Car{
    private:
        string make;
        int yearModel;
        int speed;
    public:
        //constructor
        Car();
        Car(string, int, int);
        //setters
        void accelerate()
        {speed +=5;}
        void brake ();
        //{speed -= 5;}       
        void setMake(string);
        void setYear(int);
        void setSpeed(int);
        //getters
        string getMake() const;
        int getYear() const;
        int getSpeed() const;
};

#endif	/* CAR_H */

