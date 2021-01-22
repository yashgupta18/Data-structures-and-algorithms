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

#define R 4
#define C 4


int rowWithMax1s(bool mat[R][C]){
	int ans=0;
	int i=0, j=C-1;
	while(i<R && j>=0){
		if(mat[i][j]==1){
			ans=i;
			j--;
		}
		else{
			i++;
		}
	}
	return ans;
}


int main()  
{  
    bool mat[R][C] = { {0, 0, 0, 1},  
                    {0, 1, 1, 1},  
                    {1, 1, 1, 1},  
                    {0, 0, 0, 0}};  
  
    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);  
  
    return 0;  
}  