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
#include <unordered_map>
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

#define M 4
#define N 4


void nsr(vector<int> &smallRight, int n, int arr[]){
	stack<pair<int, int> > s;
	for (int i = n-1; i >= 0; --i)
	{
		if(s.size()==0){
			smallRight.push_back(n);
		}
		else if(s.size()>0 && s.top().first < arr[i]){

			smallRight.push_back(s.top().second);
		}
		else if(s.size()>0 && s.top().first>= arr[i]){

			while(s.size()>0 && s.top().first>=arr[i]){
				s.pop();
			}


			if(s.size()==0){
				smallRight.push_back(n);

			}
			else{
				smallRight.push_back(s.top().second);
			}
		}
		s.push(make_pair(arr[i], i));

	}
	reverse(smallRight.begin(), smallRight.end());
}

void nsl(vector<int> &smallLeft, int n, int arr[]){
	stack<pair<int, int> > s;
	for (int i = 0; i < n; ++i)
	{
		if(s.size()==0){
			smallLeft.push_back(-1);
		}
		else if(s.size()>0 && s.top().first < arr[i]){

			smallLeft.push_back(s.top().second);
		}
		else if(s.size()>0 && s.top().first>= arr[i]){

			while(s.size()>0 && s.top().first>=arr[i]){
				s.pop();
			}


			if(s.size()==0){
				smallLeft.push_back(-1);

			}
			else{
				smallLeft.push_back(s.top().second);
			}
		}
		s.push(make_pair(arr[i], i));

	}


}

int histArea(int arr[], int n){
	vector<int> smallLeft;
	vector<int> smallRight;
	nsl(smallLeft, n, arr);
	nsr(smallRight, n, arr);
	int width[n];

	for (int i = 0; i < n; ++i)
	{
		width[i]=smallRight[i]-smallLeft[i]-1;
	}

	int maxArea=0;
	for (int i = 0; i < n; ++i)
	{
		maxArea=max(maxArea, width[i]*arr[i]);
	}
	return maxArea;

}


int main()  
{  
    int arr[] = {6,2,5,4,5,1,6};  
    int n=sizeof(arr)/sizeof(arr[0]);    
	cout<<histArea(arr, n);
    return 0;  
}  