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

using namespace std;

 



int palindromeArr(int arr[], int n){
	int i=0, j=n-1, count=0;
	while(i<j){
		if(arr[i]==arr[j]){
			i++;
			j--;
		}
		else if(arr[i]>arr[j]){
			j--;
			count++;
			arr[j]=arr[j]+arr[j+1];
		}
		else{
			i++;
			count++;
			arr[i]=arr[i]+arr[i-1];
		}
	}
	return count;
}


int main()
{

    //EXPLAINATION:  https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation
    int arr[] = {1, 4, 5, 9, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<palindromeArr(arr,n);

	

    return 0;
}