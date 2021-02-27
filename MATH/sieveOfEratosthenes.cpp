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
#define N 120

void sieveOferas(){
	// bitset<N> bset;
	vector<bool> bset(N+1, true);
	// memset(bset, 1, sizeof(bset));
	bset[0]=bset[1]=0;

	for (int i = 2; i < N; ++i)
	{
		//if(it is true and within limits, false all the numbers divisible by it)
		if(bset[i] && i*i<=N){
			for (int j = i*i; j <=N; j+=i)
			{
				bset[j]=0;
			}
		}
	}

	for (int i = 0; i <=N; ++i)
	{
		if(bset[i]){
			cout<<i<<" ";
		}
	}
}


int main(){

	sieveOferas();

	return 0;
}
