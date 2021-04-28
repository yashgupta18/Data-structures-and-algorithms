// https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

// Problem Description

// Given an arbitrary unweighted rooted tree which consists of N nodes.

// The goal of the problem is to find largest distance between two nodes in a tree.

// Distance between two nodes is a number of edges on a path between the nodes (there will be a unique 
// path between any pair of nodes since it is a tree).

// The nodes will be numbered 0 through N - 1.

// The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). 
// Exactly one of the i's will have A[i] equal to -1, it will be root node.



#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

pair<int,int> BFS(int root,vector<vector<int> > &G, int n){
    queue<int> q;
    int dist[n];
    memset(dist, -1, sizeof(dist));
    q.push(root);
    dist[root]=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<G[t].size(); i++){
            int currN=G[t][i];
            if(dist[currN]==-1){
                dist[currN]=dist[t] + 1;
                q.push(currN);
            }
        }
    }
    
    int maxDis=INT_MIN, nodeidx;
    for(int i=0;i<n;i++){
        if(dist[i]>maxDis){
            maxDis=dist[i];
            nodeidx=i;
        }
    }
    return make_pair(nodeidx, maxDis);
}

int solve(vector<int> &A) {
    int n = A.size();
	if(n==0 || n==1)
	return 0;
	if(n==2)
	return 1;

	vector<vector<int> > G(n);
	int root=0;
	for(int i=0; i<n; i++)
	{
	    if(A[i]==-1)
	    root = i;
	    else
	    {
	        G[A[i]].push_back(i);
	        G[i].push_back(A[i]);
	    }    
	}


    pair<int, int> a,b;
    a=BFS(root, G, n);
    cout<<a.first<<" "<<a.second<<endl;
    b=BFS(a.first, G, n);
    cout<<b.first<<" "<<b.second<<endl;
    return b.second;
}


int main()
{	
	vector<int> A;
	A.push_back(-1);
	A.push_back(0);
	A.push_back(0);
	A.push_back(0);
	A.push_back(3);
	
    cout<<solve(A);
 
    return 0;
}