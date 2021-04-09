#include <iostream>
#define ll  long long
using namespace std;
typedef pair<int, pair<int, int> > ppi;

int main()
{ 

	ll tc;
    cin>>tc;
    while(tc--){
        ll N,E,H,A,B,C.
        cin>>N>>E>>H>>A>>B>>C;
        if(E<(N*2) && H<(N*3) && (E<N && H<N)) return -1;
        
        priority_queue<ppi,vector<ppi >,greater<ppi > > min_heap;

        min_heap.push(make_pair(A, 2));
        min_heap.push(make_pair(B, 3));
        min_heap.push(make_pair(C, 1));

        while(!min_heap.empty()){
        	int minCost=min_heap.top().first;
        	int minCostQ=min_heap.top().second;
        	while()
        	min_heap.pop();
        }


    }

    return 0;
}