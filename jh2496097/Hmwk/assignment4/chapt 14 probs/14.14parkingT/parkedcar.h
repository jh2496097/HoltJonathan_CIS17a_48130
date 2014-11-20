/* 
 * File:   parkedcar.h
 * Author: Jonathan
 *
 * Created on November 6, 2014, 10:27 AM
 */

#ifndef PARKEDCAR_H
#define	PARKEDCAR_H
#include <string>
using namespace std;
class ParkedCar{
    private:
        int mins;
        string make;
        string model;
        string license;
        string color;
    public:
        ParkedCar();
        ParkedCar(int,string, string, string, string);
        void output() const;
        //mutators
        void setAll (int, string, string, string, string);
        void setMins(int m);//{ mins =m; }
        void setMake(string m);//{make=m;}
        void setModel(string m);//{model=m;}
        void setLicense(string l);//{license=l;}
        void setColor(string c);//{color =c;}
        //accessors
        int getMins () const{return mins;}
        string getMake() const{return make;}
        string getModel() const{return model;}
        string getLicense() const{return license;}
        string getColor() const{return color;}  
};


#endif	/* PARKEDCAR_H */

