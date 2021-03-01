#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include<cstdlib>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
 

#include<iostream>
#include<cstdlib>
 
using namespace std;
 
// Swapping two values.
void swap(int *a, int *b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
 
// Partitioning the array on the basis of values at high as pivot value.
int Partition(int a[], int low, int high)
{
	int pivot, index, i;
	index = low;
	pivot = high;
 
	// Getting index of the pivot.
	for(i=low; i < high; i++)
	{
		if(a[i] < a[pivot])
		{
			swap(&a[i], &a[index]);
			index++;
		}
	}
	// Swapping value at high and at the index obtained.
	swap(&a[pivot], &a[index]);
 
	return index;
}

 
int QuickSort(int a[], int low, int high)
{
	int pivot;
	if(low < high)
	{
		// Partitioning array using randomized pivot.
		pivot = Partition(a, low, high);
		// Recursively implementing QuickSort.
		QuickSort(a, low, pivot-1);
		QuickSort(a, pivot+1, high);
	}
	return 0;
}
 
int main()
{
	int n=10, i;
 
	int arr[]={3,12,1,9,4,6,2,33,14,90};
 
	QuickSort(arr, 0, n-1);
 
	// Printing the sorted data.
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        	cout<<"->"<<arr[i];
 
	return 0;
}