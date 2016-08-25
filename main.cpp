
/*********************************************************************
** Program Filename: main Lab H
** Author: Tyler Forrester
** Date: 8/12/2016
** Description: A program that takes a text file full of integers and performs operations on them
** Input: File of Integers
** Output: Timing of mergesort Algorimths
** Citations:http://www.cplusplus.com/doc/tutorial/files/ and http://www.cplusplus.com/forum/general/76107/ and http://code.runnable.com/UpSpP5ymsslIAAFo/reading-a-file-into-an-array-for-c%2B%2B-and-fstream
** Citations: Timing Function Roger Pate May 11, 2010 6:34    http://stackoverflow.com/questions/2808398/easily-measure-elapsed-time
********************************************************************/

#include <algorithm>
#include <iostream>
#include <fstream>
#include "InputValid.hpp"
#include "WriteFile.hpp"
#include "Sort.hpp"
#include <ctime>
#include "Dice.h"


using std::ifstream;
using std::cout;
using std::ofstream;
using std::endl;


int main() {
	
	void printArray(std::vector<int> A);
	void displayMenu();
	int getChoice(InputValid);
	void continueOn(InputValid);
	int choice;
	InputValid valid = InputValid();  // creates validation
	WriteFile file = WriteFile();
	void randomIntegerFile(InputValid valid);
	Sort sort = Sort(); 
	int length; 
	int length1; 

	do {

		displayMenu();
		choice = getChoice(valid);
	//	length = 0; 
	//	length1 = 0; 
	    randomIntegerFile(valid);
		randomIntegerFile(valid);
		std::vector<int> nums = file.readInt();
		std::vector<int> nums1 = file.readInt();

	
		
		//	int arr[] = { 12, 11, 13, 5, 6, 7 };
		//	int n = sizeof(nums) / sizeof(arr[0]);
			
		/*	printf("Given array is \n");
			printArray(nums, length); */
			
			clock_t begin = clock(); // Timing Function Roger Pate May 11, 2010 6:34 
									//  http ://stackoverflow.com/questions/2808398/easily-measure-elapsed-time
			sort.interMergeSort(nums, nums.size());
			
			clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			
			cout << "The total elapse time on iterative merge sort is: " << elapsed_secs << ".\n";

		//	printf("\nSorted array is \n");
		//	printArray(nums);

			//int arr1[] = { 12, 11, 13, 5, 6, 7 };
			//int arr_size = sizeof(arr1) / sizeof(arr1[0]);

		//	printf("Given array is \n");
		//	printArray(nums1);
			 begin = clock();
			
			 sort.recurMergeSort(nums1, 0, nums1.size() - 1);
			
			 end = clock();
			 double elapsed_secs1 = double(end - begin) / CLOCKS_PER_SEC;
					
		//	printf("\nSorted array is \n");
		//	printArray(nums1);

			cout << "The total elapse time on  recursive merge sort is: " << elapsed_secs1 << ".\n";


			//printf("\nSorted array is \n");
		//	printArray(nums1);
		

	
			
			
	}while (choice == 1);

		return 0;
}



/*********************************************************************
** Function: displayMenu
** Description: Displays Menu of Options for Sum Game
** Parameters: void
** Pre-Conditions: Start of Program
** Post-Conditions: getChoice()
** Citation: Starting Out C++: Early Objects (8th Edition) Program 6-14 Gaddis P. 352
*********************************************************************/


void displayMenu() {


	cout << "\nWelcome to Lab 6\nPlease Select a Number\n\n";
	cout << "1. Time Merge Sort Iterative and Merge Sort Recursive.\n";
	cout << "Any other integer quits.\n";




}
/*********************************************************************
** Function:  getChoice
** Description: gets number of Choice
** Parameters:  InputValid
** Pre-Conditions: DisplayMenu()
** Post-Conditions: Switch and Array Entry
** Citation: Starting Out C++: Early Objects (8th Edition) Program 6-14 Gaddis P. 352
*********************************************************************/


int getChoice(InputValid valid) {

	int choice;
	choice = valid.validateInt();
/*	while (choice < 1 || choice > 4) {

		cout << "The only valid choices are 1 or 2. Please re-enter.\n";
		choice = valid.validateInt();

	} */

	return choice;




}


/*********************************************************************
** Function:  continueOn
** Description: Pauses program after tasks
** Parameters: InputValid
** Pre-Conditions: switch case 1, case 2 and case 3
** Post-Conditions: displaymenu()
** Citation:
*********************************************************************/

void continueOn(InputValid valid) {
	char entry = '0';
	do {


		cout << "Please enter 'c' to continue.\n";
		entry = valid.validateChar();



	} while (entry != 'c');

}

/*********************************************************************
** Function:  printArray
** Description: prints array
** Parameters: array, integer
** Pre-Conditions: 
** Post-Conditions:
** Citation: http://www.geeksforgeeks.org/iterative-merge-sort/
*********************************************************************/

/* Function to print an array */
void printArray(std::vector<int> A)
{

	for (int i = 0; i < A.size(); i++)
		printf("%d ", A[i]);
	printf("\n");
}





/*********************************************************************
** Function: randomIntegerFile
** Description: creates random integer file with user input 
** Parameters: InputValid Valid
** Pre-Conditions: program start
** Post-Conditions:rest of program
** Citation: 
*********************************************************************/

void randomIntegerFile(InputValid valid) {

	//use zeros for spacing 
	int number; 
	int array_size;
	WriteFile write = WriteFile();

	char b1[75];
	
	cout << "Please enter a file name. The integers will be saved in this file. " << endl;

	std::cin.getline(b1, 75);

	ofstream myfile1(b1);


	cout << "Please enter in the number of digits in your file.\n";
		number = valid.validateInt();
		array_size = 2 * number; 


	//cout << "Array Size intial.\n";
	Dice dice = Dice(array_size);
	// cout << "Dice intial.\n";
	int * randomInt = new int[array_size];
	//cout << "RandomInt intial.\n";
	for (int i; i < array_size ; i++) {
	//	cout << "This is a array_size " << array_size << ".\n";
	//	cout << "This is I " << i << ".\n";
		randomInt[i] = dice.roll(); 
	//	cout << "This is a random int " << randomInt[i] << ".\n";
	}
	//cout << "Before the printout statement.\n";
	/*for (int i = 0; i < array_size; i++)
		printf("%d ", randomInt[i]);
	printf("\n"); */
	
   write.writeInt(randomInt, array_size, myfile1);
	
	delete[]randomInt; 
}