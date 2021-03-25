#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
#include <iomanip>      // std::setprecision
#include <algorithm>
#include <unordered_map>


#define ll long long int
using namespace std;



int main() {
	ll tc;
	cin>>tc;
	while(tc--){
		ll n; cin>>n;
		int arr[n];
		unordered_map<int, int> mp;
		for (int i = 0; i < n; ++i)
		{
			/* code */
			cin>>arr[i];
			mp[arr[i]]++;
		}

		int even=0, odd=0,uniq=0;
		for(auto i: mp){
			uniq++;
			if(i.second%2==0){
				even++;
			}else{
				odd++;
			}
		}

		if(uniq%2==0)

	}
	return 0;
}


