/* 
 * File:   employee.h
 * Jonathan Holt
 *
 * Created on November 1, 2014, 3:34 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <string>
using namespace std;
class Employee{
    private:
        string name;
        int idNum;
        string department;
        string position;    
    public:
        //constructors
        Employee();
        //{ name ="", idNum =0, department="", position =""; }
        Employee(string, int, string, string);
        Employee(string, int);
        //destructor ~employee();
        //setters
        void setName(string);
        void setNum (int);
        void setDepart(string);
        void setTitle (string);
        //getters
        string getName() const; //{return name;}
        int getID () const; //{return idNum;}
        string getDepart() const;// {return department; }
        string getTitle()  const;// {return position; }
        
};

#endif	/* EMPLOYEE_H */

