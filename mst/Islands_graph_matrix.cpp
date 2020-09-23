
#include<iostream>
// #define V 5
 #define ROW 5
 #define COL 5
using namespace std;


bool isSafe(int M[][COL], int row, int col, bool vis[ROW][COL]){
        return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !vis[row][col]); 
    }
    
    //USING DFS
    void dfs_islands(int M[][COL], bool vis[][COL], int row,int col){
        int rows[]={-1,-1,-1, 0,  1, 1, 1 ,0 };
        int cols[]={1 , 0 ,-1,-1,-1, 0, 1, 1 };

        vis[row][col]=true;
        for (int k = 0; k < 8; ++k)
        {
            if(isSafe(M,row+rows[k],col+cols[k], vis)){
                dfs_islands(M,vis, row+rows[k], col+cols[k]);
            }   
        }
        return;
        
    }   

    //USING BFS
    // void BFS(int mat[R][COL], bool vis[R][COL], 
    //      int si, int sj) 
    // { 
  
    // // These arrays are used to get row and 
    // // column numbers of 8 neighbours of 
    // // a given cell 
    // int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    // int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
  
    // // Simple BFS first step, we enqueue 
    // // source and mark it as visited 
    // queue<pair<int, int> > q; 
    // q.push(make_pair(si, sj)); 
    // vis[si][sj] = true; 
  
    // // Next step of BFS. We take out 
    // // items one by one from queue and 
    // // enqueue their univisited adjacent 
    // while (!q.empty()) { 
  
    //     int i = q.front().first; 
    //     int j = q.front().second; 
    //     q.pop(); 
  
    //     // Go through all 8 adjacent 
    //     for (int k = 0; k < 8; k++) { 
    //         if (isSafe(mat, i + row[k],j + col[k], vis)) { 
    //          vis[i + row[k]][j + col[k]] = true; 
    //          q.push(make_pair(i + row[k], j + col[k])); 
    //         } 
    //     } 
    // } 
    // } 
    
    int  countIslands(int M[][COL]){
        bool vis[ROW][COL];
        memset(vis, 0, sizeof(vis)); 

        int count=0;

        for (int i = 0; i < ROW; ++i)
        {
            for (int j = 0; j < COL; ++j)
            {
                int node=M[i][j];
                if(node & !vis[i][j]){
                    dfs_islands(M,vis, i,j);
                    count=count+1;
                }
            }
        }

        // cout<<count;
        return count;
    }


int main(){

//No of islands
    int M[][COL] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } }; 
  
    cout << "Number of islands is: " << countIslands(M); 


    return 0;
}
