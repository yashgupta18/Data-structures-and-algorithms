#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<cstring>
#include<bitset>
#include<regex>
#define int int64_t
using namespace std;

int32_t main(){
	int n, m, k, ans=0;
	cin>>n>>m>>k;
	bitset<32> arr[m+1];

	for (int i = 0; i < m+1; ++i)
	{
		int x;
		arr[i]=x;
	}

	for (int i = 0; i < m; ++i)
	{
		int k_diff=0;
		for (int j = 0; j < 32; ++j)
		{
			/* code */
			
			if(arr[m][j]!=arr[i][j]){
				k_diff++;
			}
		}
		if(k_diff<=k){
			ans++;
		}
	}

	cout<<ans<<"\n";
	return 0;
}