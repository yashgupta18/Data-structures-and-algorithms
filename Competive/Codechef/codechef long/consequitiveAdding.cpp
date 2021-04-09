#include <iostream>
#include <string>

#define ll long long int
using namespace std;


bool recursive(ll C, ll R, ll matA[][], ll matB[][]){
	if(i>R || j>C || i<0 || j<0) return 0;
	if(C==0){
		for(int i=0; i<R; i++){
			matA=
		}
	}
	if(R==0){

	}
	
}


int main() {
	// your code goes here
	ll tc;
	cin>>tc;
	while(tc--){
	    ll R,C,X;
	    cin>>R>>C>>X;
	    ll matA[R][C];
	    ll matB[R][C];
	    for (ll i = 0; i < R; ++i)
	    {
			for (ll j = 0; j < C; ++j)
			{
				cin>>matA[i][j];
			}
	    }

	    for (ll i = 0; i < R; ++i)
	    {
			for (ll j = 0; j < C; ++j)
			{
				cin>>matB[i][j];
			}
	    }
	}
	return 0;
}

