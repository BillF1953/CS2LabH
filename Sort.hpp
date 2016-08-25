/*********************************************************************
** Program Filename : Sort Header
** Author : Tyler Forrester
** Date : 8/ 3 / 2016
* * Description : Sorst Arrays
** Input : Arrays
** Output : Sorted arrays
** Citations :
********************************************************************/



#ifndef  SORT_HPP
#define  SORT_HPP
#include<stdlib.h>
#include<stdio.h>
#include <iostream>
#include <vector>

class Sort {
private:

public:
	int * bubble(int *, int);
	void recurMergeSort(std::vector<int>& arr, int l, int r);
	void recurMerge(std::vector<int>& arr, int l, int m, int r);
	int min(int x, int y);
	void interMergeSort(std::vector<int>& arr, int n);
	void interMerge(std::vector<int> &arr, int l, int m, int r);



};

#endif
