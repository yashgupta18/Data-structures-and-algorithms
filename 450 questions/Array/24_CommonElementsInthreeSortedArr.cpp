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
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;



void commonFind(int arr1[], int arr2[], int arr3[], int n, int m,  int o){
	int a=0, b=0, c=0;
	while(a<n && b<m && c<o){
		if(arr1[a]==arr2[b] && arr2[b]==arr3[c]){
			cout<<arr1[a]<<endl;
			a++;
			b++;
			c++;

		}

		else {

			if(arr1[a]<arr2[b] && arr1[a]<arr3[c]){
				a++;
			}
			else if(arr2[b]<arr1[a] && arr2[b]<arr3[c]){
				b++;
			}
			else{
				c++;
			}

		}
	}
	return;

}


int main()
{

    int arr1[] = {1, 5, 10, 20, 40, 80};
	int arr2[] = {6, 7, 20, 80, 100};
	int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
	int n=sizeof(arr1)/sizeof(arr1[0]);
	int m=sizeof(arr2)/sizeof(arr2[0]);
    int o=sizeof(arr3)/sizeof(arr3[0]);
    commonFind(arr1, arr2,arr3, n, m, o);

	
    return 0;
}