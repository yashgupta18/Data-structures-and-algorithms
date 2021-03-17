#include <iostream>
#include <string>

#define ll long long int
using namespace std;
// Q. https://www.codechef.com/problems/PALPALS
int main() {
	// your code goes here
	ll tc;
	cin>>tc;
	while(tc--){
	    int m,n;
	    cin>>m;
	    cin>>n;

	    int grp=0;
	   	vector<pair<int, int> > d;
	    for (int i = 0; i < n; ++i)
	    {
	    	int di, pi;
	    	cin>>di>>pi;
	    	d.push_back(make_pair(di, pi));
	    	// p.push_back(pi);
	    }

	    sort(d.begin())


	    
	}
	return 0;
}

