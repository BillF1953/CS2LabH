/*********************************************************************
** Program Filename: Dice CPP File
** Author: Tyler Forrester
** Date: 6/27/2016
** Description: A file that sets the number of sides on a dice then rolls the dice.   
** Input: 
** Output: A random dice roll and the number of sides
** Citations: Object Oriented Programming Using C++ Fourth Edition Joyce Farrell
********************************************************************/





#include "Dice.h"
/*********************************************************************
** Function: Default Dice Constructor
** Description: sets divisor to 6. 
** Parameters: none
** Pre-Conditions: Object created
** Post-Conditions: LoadedDice.Roll(), Roll()
** Citation: Object Oriented Programming Using C++ Fourth Edition Joyce Farrell Appendix E
*********************************************************************/

Dice::Dice()
{
	setDivisor(6);
}

/*********************************************************************
** Function: Override Dice Constructor
** Description: allows divisor to be set to any int. Changing sides on dice. 
** Parameters: int d
** Pre-Conditions: Object created
** Post-Conditions: LoadedDice.Roll(), Roll()
** Citation: Object Oriented Programming Using C++ Fourth Edition Joyce Farrell Appendix E
*********************************************************************/

Dice::Dice(int d)
{ 
	setDivisor(d);
}
/* This sets the divisor which dictates the number of sides*/
void Dice::setDivisor(int a)
{
	divisor = a; 
}
/*********************************************************************
** Function: seed()
** Description: seeds the system time into random to provide a random nuber
** Parameters: void
** Pre-Conditions: First function call in main
** Post-Conditions: rest of program
** Citation: Object Oriented Programming Using C++ Fourth Edition Joyce Farrell Appendix E
*********************************************************************/

void Dice::seed()
{
	srand((unsigned)time(NULL));

}
/* This gets the divisor which dictates the number of sides*/
int Dice::getDivisor()
{
	return divisor;
}

/*********************************************************************
** Function: roll()
** Description: rolls a random dice that can be initialized to many sides
** Parameters: const int nums[], int size
** Pre-Conditions: divisor must have sides. 
** Post-Conditions: LoadedDice.Roll()
** Citation: Object Oriented Programming Using C++ Fourth Edition Joyce Farrell Appendix E
*********************************************************************/
int Dice::roll()
{
	
	int result = 1 + (rand() % divisor);
	return result;
}
