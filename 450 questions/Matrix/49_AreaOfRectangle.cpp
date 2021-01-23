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


void nsr(vector<int> &smallRight, int arr[]){
	stack<pair<int, int> > s;
	for (int i = N-1; i >= 0; --i)
	{
		if(s.size()==0){
			smallRight.push_back(N);
		}
		else if(s.size()>0 && s.top().first < arr[i]){

			smallRight.push_back(s.top().second);
		}
		else if(s.size()>0 && s.top().first>= arr[i]){

			while(s.size()>0 && s.top().first>=arr[i]){
				s.pop();
			}


			if(s.size()==0){
				smallRight.push_back(N);

			}
			else{
				smallRight.push_back(s.top().second);
			}
		}
		s.push(make_pair(arr[i], i));

	}
	reverse(smallRight.begin(), smallRight.end());
}

void nsl(vector<int> &smallLeft, int arr[]){
	stack<pair<int, int> > s;
	for (int i = 0; i < N; ++i)
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

int histArea(int arr[]){
	vector<int> smallLeft;
	vector<int> smallRight;
	nsl(smallLeft, arr);
	nsr(smallRight, arr);
	int width[N];

	for (int i = 0; i < N; ++i)
	{
		width[i]=smallRight[i]-smallLeft[i]-1;
	}

	int maxArea=0;
	for (int i = 0; i < N; ++i)
	{
		maxArea=max(maxArea, width[i]*arr[i]);
	}
	return maxArea;

}

int rectArea(bool mat[M][N]){
	int arr[N];
	for (int i = 0; i < N; ++i)
	{
		/* code */
		arr[i]=mat[0][i];
	}
	int maxArea=histArea(arr);
	for (int i = 1; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			/* code */
			if(mat[i][j]==0){
				arr[j]=0;				
			}else{
				arr[j]=arr[j]+mat[i][j];
			}
		}
		maxArea=max(maxArea,histArea(arr));
	}

	return maxArea;
}


int main()  
{  
    bool mat[M][N] = {
    				{0,1,1,0},
					{1,1,1,1},
					{1,1,1,1},
					{1,1,0,0},
					};  
	cout<<rectArea(mat);
    return 0;  
}  