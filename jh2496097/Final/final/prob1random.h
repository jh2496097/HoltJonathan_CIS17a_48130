/* 
 * File:   prob1random.h
 * Author: Jonathan
 *
 * Created on December 8, 2014, 2:26 PM
 */

#ifndef PROB1RANDOM_H
#define	PROB1RANDOM_H

class Prob1Random
{
	private:
		unsigned char *set;      //The set of numbers to draw random numbers from
		char  nset;     //The number of variables in the sequence
		int  *freq;     //Frequency of all the random numbers returned
		int   numRand;  //The total number of times the random number function is called
	public:
		Prob1Random(const char,const unsigned char *);   //Constructor
		~Prob1Random();                       //Destructor
		char randFromSet();                   //Returns a random number from the set
		int *getFreq() const{return freq;}      //Returns the frequency histogram
		unsigned char *getSet() const{return set;}       //Returns the set used
		int getNumRand() const{return numRand;} //Gets the number of times randFromSet has
		                                        //been called
};

#endif	/* PROB1RANDOM_H */

