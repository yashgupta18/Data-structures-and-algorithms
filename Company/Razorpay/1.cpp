// https://www.hackerearth.com/problem/algorithm/bfs-waali-7409c2ca-c1be890b/

// Problem
// There is an island in the form of MxN grid where each cell either has a tower built on it or is empty. Each cell is a square of unit area and each tower has a height of 1 unit.
// Monsoon has come and rain has started, The king of the island wants to estimate how much volume of water would be trapped in between the towers.
// Water will be trapped, only if it does not reach to the corner and flows out. Water from the current cell can reach to another cell only if that cell shares an edge with the current cell.

// Constraints
// 1<= MxN <= 1000000

// INPUT
// The first line will contain two integers M and N, then the following lines will contain a grid of MxN, where ''* denotes that cell is blocked and '.' denotes that it is empty.

// OUTPUT
// The output would contain the volume of water trapped.




#include <iostream>
#include<stdio.h>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<cmath>
#include<string>

#include<vector>
using namespace std; 

#define ll long long
#define pb push_back
#define mk make_pair

const ll mod = 1e9 + 7;

ll n, m;
vector<string> s;
void dfs(ll r, ll c) {
    ll i, j;
    s[r][c] = 'v';
    ll moves[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for(i = 0; i < 4; i++) {
        ll temp_r = r+moves[i][0], temp_c = c+moves[i][1];
        if(temp_r < n && temp_r >= 0 && temp_c < m && temp_c >= 0 && s[temp_r][temp_c] == '.')
            dfs(temp_r, temp_c);
    }
}
int main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0); 
    int t = 1;
    // cin >> t;
    while(t--) {
        ll i, j, ans = 0;
        cin >> n >> m;
        string temp;
        for(i = 0; i < n; i++)
            cin >> temp, s.pb(temp);
        for(i = 0; i < n; i++)
            if(s[i][0] == '.')
                dfs(i, 0);
        for(i = 0; i < n; i++)
            if(s[i][m-1] == '.')
                dfs(i, m-1);
        for(j = 0; j < m; j++)
            if(s[0][j] == '.')
                dfs(0, j);
        for(j = 0; j < m; j++)
            if(s[n-1][j] == '.')
                dfs(n-1, j);
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                if(s[i][j] == '.')
                    ans++;
        cout << ans << endl;        
    }
    return 0; 
}