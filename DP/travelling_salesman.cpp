#include<iostream>
using namespace std;
#define INF 999999

int n=4;
int dp[16][4];

int dist[10][10] = { 
					{0, 20, 42, 25},  
                    {20, 0 , 30, 34},  
                    {42, 30, 0 ,10},  
                    {25, 34, 10, 0}  
                    };  

//bit for all cities visited 1111
int VISITED_ALL=(1<<n)-1;
//mask= cities visited- 1 for visited, 0 for not vis.
// pos= current city index 
int tsp(int mask, int pos){
	if(mask==VISITED_ALL){
		//dist of last to first 
		return dist[pos][0];
	}

	if(dp[mask][pos]!=-1){
		return dp[mask][pos];
	}

	int ans=INF;

	 for (int city = 0; city < n; ++city)
	 {
	 	//if city is not visited 
	 	if((mask&(1<<city))==0){
	 		int newAns=dist[pos][city] + tsp(mask|(1<<city), city);
	 		ans=min(ans, newAns);
	 	}
	 }
	 return dp[mask][pos]=ans;
}

int main(){
	for (int i = 0; i < (i<<n); ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dp[i][j]=-1;
		}
	}
	cout<<tsp(1, 0)<<endl;
	return 0;
}