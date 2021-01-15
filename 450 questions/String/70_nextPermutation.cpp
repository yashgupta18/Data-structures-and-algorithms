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
#include <unordered_set>
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


void nextPermutation(int arr[], int n) {
    int small, big;
    for (int i = n-1; i >=0 ; --i)
    {
        if(arr[i]<arr[i+1]){
            small=i;
            break;
        }
        /* code */
    }
    for (int i = n-1; i >=0 ; --i)
    {
        if(arr[i]>small){
            big=i;
            break;
        }
        /* code */
    }

    swap(arr[small],arr[big]);
    reverse(arr+small+1, arr+n);

    for (int i = 0; i < n; ++i)
    {
        cout<<arr[i]<<" ";
    }
return;

}


int main() 
{ 
	int arr[] = {1, 2, 3, 6, 5, 4};
    int n=sizeof(arr)/sizeof(arr[0]);
    nextPermutation(arr, n);
    return 0; 
} 
