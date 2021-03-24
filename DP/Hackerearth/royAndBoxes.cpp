// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/

#include <iostream> 
#include <vector> 
#include <cmath> 
#include<sstream>
#define ll long long int
using namespace std; 
// Driven program to test 
ll ranges[1000005],coins[1000005];
int main() 
{ 
	for (int i = 0; i <= 1000000; ++i)
    {
    	/* code */
    	ranges[i]=coins[i]=0;
    }

    int N,M;
	cin>>N>>M;
	while(M--){
		int l,r;
		cin>>l>>r;
		ranges[l]++;
        ranges[r+1]--;
	}

	for (int i = 1; i <= 1000000; ++i)
    {
    	ranges[i]+=ranges[i-1];
    }
    
    for (int i = N-1; i >=0 ; --i)
    {
    	coins[ranges[i]]++;
    }

    for (int i = N-1; i>=0; --i)
    {
    	coins[i]+=coins[i+1];
    }

    

    int q;
    cin>>q;
    while(q--){
    	int x;
    	cin>>x;
    	cout<<coins[x]<<"\n";
    }
    
    return 0; 
} 






