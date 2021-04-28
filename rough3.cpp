pair<int,int> bfs(vector<vector<int>> graph, int root, int depth=0){

int max_path_len=0,max_path_node=root;
int n = graph.size();
vector<int>distance(n,INT_MAX);
distance[root]=0;
vector<int> visited(n,0);
queue<int> q;
visited[root]=1;
q.push(root);

while(!q.empty()){
    int front = q.front();
    q.pop();
    for(int i=0;i<graph[front].size();i++){
        int neighbor = graph[front][i];
        if(visited[neighbor]==0){
            distance[neighbor]=distance[front]+1;
            visited[neighbor]=1;
            q.push(neighbor);
            if(distance[neighbor] > max_path_len){
                max_path_len=distance[neighbor];
                max_path_node=neighbor;
            }
            max_path_len=max(max_path_len,distance[neighbor]);
        }
    }
}
return make_pair(max_path_len,max_path_node);
}

int Solution::solve(vector &A) {

int n=A.size();
if(n<=1)
    return 0;
    
vector<vector<int>> graph(n);
int root;

// create graph
for(int i=0;i<n;i++){
    if(A[i]==-1)
        root=i;
    else{
        graph[i].push_back(A[i]);
        graph[A[i]].push_back(i);
    }
}

pair<int,int> node;
node = bfs(graph,root);

int soln;
soln = bfs(graph,node.second).first;
return soln;    
}