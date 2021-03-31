#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
#include <iomanip>      // std::setprecision
#include <algorithm>

#define ll long long int
using namespace std;


// https://codeforces.com/problemset/problem/200/B
int main() {
	
    ll n;
    cin>>n;
    double arr[n];
    for (int i = 0; i < n; ++i)
    {
    	 cin>>arr[i];

    }
    
    double totalpc=100.0/n;
    double sum=0;
    for (int i = 0; i < n; ++i)
    {
    	/* code */
    	arr[i]= (arr[i]*totalpc)/100;
    	sum+=arr[i];
    }

    cout<<fixed << setprecision(12)<<sum<<endl;
	
	return 0;
}


