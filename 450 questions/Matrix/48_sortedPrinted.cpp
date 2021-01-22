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


int sortedPrint(int mat[M][N]){
	priority_queue< pair<int,pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int,pair<int, int> > > > min_heap;
	for (int i = 0; i < N; ++i)
	{
		/* code */
		min_heap.push(make_pair(mat[i][0], make_pair(i,0)));

	}
	int count=0;
	while(count<(M*N)){
		int num=min_heap.top().first;
		int i=min_heap.top().second.first;
		int j=min_heap.top().second.second;
		cout<<num<<" ";
		count++;
		min_heap.pop();
		if(j+1<N){
			min_heap.push(make_pair(mat[i][j+1], make_pair(i, j+1)));

		}
	}

}


int main()  
{  
    int mat[M][N] = { {10, 20, 30, 40}, 
                    {15, 25, 35, 45}, 
                    {24, 29, 37, 48}, 
                    {32, 33, 39, 50}, 
                }; 
  
	 sortedPrint(mat);
    return 0;  
}  