#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

int find_set(int u, int v, int parent[]){
  if(u==parent[u] || parent[u]==v){
    return parent[u];
  }
  else{
    return parent[u]=find_set(parent[u],v, parent);
  }
}


int main() {	
		
	    ll n, q;
	    cin>>n>>q;
	    int parent[n+1];
    	// int rank[n];
	    
    	for (int i = 0; i < n; ++i)
    	{
    		/* code */
    		parent[i]=i;
    	}

	    // memset(rank, 0, sizeof(rank));

	    for (int i = 0; i < n-1; ++i)
	    {
	    	int x,y;
	    	cin>>x>>y;
	    	parent[y]=x;
	    }	


	    // unionSet(x, y, parent, rank);

	    vector<string> ans;
	    for (int i = 0; i < q; ++i)
	    {
	    	int u,v;
	    	cin>>u>>v;
	    	int val=find_set(v, u, parent); 
	    	if(val==u) {
	    		ans.push_back("YES");
	    	}else{
	    		ans.push_back("NO");
	    	}
	    }

	    cout<<endl;
	    for (int i = 0; i < ans.size(); ++i)
	    {
	    	/* code */
	    	cout<<ans[i]<<" ";
	    }


	return 0;
}




