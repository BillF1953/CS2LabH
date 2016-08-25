/*********************************************************************
** Program Filename: Dice Header File
** Author: Tyler Forrester
** Date: 6/27/2016
** Description: A file that sets the number of sides on a dice then rolls the dice.
** Input:
** Output: A random dice roll and the number of sides
** Citations: Object Oriented Programming Using C++ Fourth Edition Joyce Farrell
********************************************************************/




#ifndef DICE_H
#define DICE_H
#include <iostream>
#include <cstdlib>
#include<ctime>
class Dice {


private:
	int divisor;

public: 
	
	Dice();
	Dice(int);
	void setDivisor(int);
	void seed();
	int getDivisor();
	int roll();
	


	


};
#endif
