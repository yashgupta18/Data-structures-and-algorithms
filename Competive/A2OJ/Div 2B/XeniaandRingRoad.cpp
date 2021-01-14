#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<cstring>
#include<regex>
#define int int64_t
using namespace std;

int32_t main(){
	int n, m;
	int initial=1, ans=0;
	cin>>n>>m;
	int arr[m];
	for (int i = 0; i < m; ++i)
	{
		/* code */
		int x;
		cin>>x;
		ans+=((x-initial+n)%n);
		initial=x;
	}
	cout<<ans<<"\n";
	return 0;
}