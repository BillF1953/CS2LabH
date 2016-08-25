/*********************************************************************
** Program Filename : Sort CPP
** Author : Tyler Forrester
** Date : 8/ 3 / 2016
* * Description : Sorst Arrays
** Input : Arrays
** Output : Sorted arrays
** Citations :
********************************************************************/



#include "Sort.hpp"

/*********************************************************************
** Function:  Bubblesort()
** Description: Sorts Array
** Parameters: integer array and size of array
** Pre-Conditions: an int array
** Post-Conditions: anything you want to with an sorted int array
** Citation: http://www.tutorialspoint.com/data_structures_algorithms/bubble_sort_algorithm.htm
** Pseudocode
1. for i = 0 until i = length -1 do
3. swapped = false
4. 	a. Let i = 0; 	b. Do the following length -1 times:
i. If A[i] > A[i+1], exchange A[i] and A[i+1]
ii. Add 1 to i
iii. swapped = true
5. else swapped = false and break

*********************************************************************/
int * Sort::bubble(int * searchArr, int length)
{ 
	// Input n 
	int n = length - 1;
	// Input a vector a values of A[0]..A[N - 1]

	// Let x = 0

	
	for (int j = 0; j < length; j++) {
		bool swapped = false;
		for (int i = 0; i < n; i++)
		{
			if (searchArr[i] > searchArr[i + 1]) {

				int temp = searchArr[i + 1];
				searchArr[i + 1] = searchArr[i];
				searchArr[i] = temp;
				swapped = true;
			}
		}
		if (!swapped) {

			break;
		}

	}

	

	/** for (int i = 0; i < length; i++)
	{
		cout << searchArr[i] << endl; for testing 
	} **/

	return searchArr;

}






/*********************************************************************
** Function:  recureMergesort()
** Description: Recursive C program for merge sort
** Parameters: integer array and size of array
** Pre-Conditions: an int array
** Post-Conditions:
** Citation: http://www.geeksforgeeks.org/iterative-merge-sort/
* Pseudocode
*********************************************************************/

/* l is for left index and r is right index of the sub-array
of arr to be sorted */
void Sort::recurMergeSort(std::vector<int> &arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2; //Same as (l+r)/2 but avoids overflow for large l & h
		recurMergeSort(arr, l, m);
		recurMergeSort(arr, m + 1, r);
		recurMerge(arr, l, m, r);
	}
}

/*********************************************************************
** Function:  Mergesort()
** Description: Recursive C program for merge sort
** Parameters: integer array and size of array
** Pre-Conditions: an int array
** Post-Conditions:
** Citation: http://www.geeksforgeeks.org/iterative-merge-sort/
* Pseudocode
*********************************************************************/


/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void Sort::recurMerge(std::vector<int> &arr, int l, int m, int r)
{
	int i, j, k;
	int array_size = m - l + 1;
	int array_size1 = r - m;

	/* create temp arrays */
	//int * L = new int[array_size];
	//int * R = new int[array_size1];
	std::vector<int> L; 
	std::vector<int> R;

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < array_size; i++)
		L.push_back(arr[l + i]);
	for (j = 0; j < array_size1; j++)
		R.push_back(arr[m + 1 + j]);

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < array_size && j < array_size1)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < array_size)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < array_size1)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	
//	delete[]L;
//	delete[]R;
}


/*********************************************************************
** Functions: iterative Mergesort()
** Description: Recursive C program for merge sort
** Parameters: integer array and size of array
** Pre-Conditions: an int array
** Post-Conditions:
** Citation: http://www.geeksforgeeks.org/iterative-merge-sort/
*********************************************************************/


/*********************************************************************
** Function: min()
** Description: smaller number
** Parameters: int x and int y
** Pre-Conditions: interMergeSort()
** Post-Conditions: interMergeSort() interMerge() 
** Citation: http://www.geeksforgeeks.org/iterative-merge-sort/
*********************************************************************/


// Utility function to find minimum of two integers
int Sort::min(int x, int y) {


	if (x < y) {
		return x;
	}
	else {
		return y;
	}

}

/*********************************************************************
** Function: iterMergesort()
** Description: Recursive C program for merge sort
** Parameters: vector int and size of vector
** Pre-Conditions: vector int
** Post-Conditions: some sorting
** Citation: http://www.geeksforgeeks.org/iterative-merge-sort/
*********************************************************************/

/* Iterative mergesort function to sort arr[0...n-1] */

void Sort::interMergeSort(std::vector<int> &arr, int n)
{
	int curr_size;  // For current size of subarrays to be merged
					// curr_size varies from 1 to n/2
	int left_start; // For picking starting index of left subarray
					// to be merged

					// Merge subarrays in bottom up manner.  First merge subarrays of
					// size 1 to create sorted subarrays of size 2, then merge subarrays
					// of size 2 to create sorted subarrays of size 4, and so on.
	for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
	{
		// Pick starting point of different subarrays of current size
		for (left_start = 0; left_start<n - 1; left_start += 2 * curr_size)
		{
			// Find ending point of left subarray. mid+1 is starting 
			// point of right
			int mid = left_start + curr_size - 1;

			int right_end = min(left_start + 2 * curr_size - 1, n - 1);
	//		std::cout << "This happened " << right_end << " times.\n";
			// Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
			interMerge(arr, left_start, mid, right_end);
		}
	}
	//std::cout << "We got out.\n";
}


/*********************************************************************
** Function: interMerge()
** Description: iterative approach to sort
** Parameters: int x and int y
** Pre-Conditions:  unsorted vector
** Post-Conditions: sorted vector
** Citation: http://www.geeksforgeeks.org/iterative-merge-sort/
*********************************************************************/
/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */

void Sort::interMerge(std::vector<int> &arr, int l, int m, int r)
{
	int i, j, k;
	int array_size = m - l + 1;
	int array_size1 = r - m;
	//std::cout << "After array_size.\n";
	//create temp arrays 
	// int * L = new int[array_size];
	//int * R = new int[array_size1];
	std::vector<int> L;
	std::vector<int> R;
	/* Copy data to temp arrays L[] and R[] */
	 for (i = 0; i < array_size; i++)
		L.push_back(arr[l + i]);
//	std::cout << "Copy data.\n";
	for (j = 0; j < array_size1; j++)
		R.push_back(arr[m + 1 + j]);

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < array_size && j < array_size1)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		//	std::cout << "Temp Array Merge.\n";
		}
		else
		{
			arr[k] = R[j];
			j++;
		//	std::cout << "Else ClauseTemp Array Merge.\n";
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	 	while (i < array_size)
	{
	//	std::cout << "Remaing of L ClauseTemp Array Merge.\n";
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	 	while (j < array_size1)
		 	{
	//	std::cout << "Remaing of R ClauseTemp Array Merge.\n";
		arr[k] = R[j];
		j++;
		k++;
	}

//	std::cout << "Delete Memory .\n";
	//delete[]L;
	//delete[]R; 
}
