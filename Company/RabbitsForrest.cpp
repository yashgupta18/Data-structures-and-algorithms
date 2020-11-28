#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include <cmath> 
using namespace std; 

// https://www.youtube.com/watch?v=9mEUIdP4ytw&ab_channel=Pepcoding
// Diff sol https://www.geeksforgeeks.org/minimum-number-of-rabbits-that-must-be-present-in-the-forest/

int countRabbits(int arr[], int n){
	
	unordered_map<int, int> mp;
	for (int i = 0; i < n; ++i)
	 {
	 	// key is keykey+1
	 	//and increasing count++;
	 	mp[arr[i]+1]++;
	 } 

	 int totalSum=0;
	 for(auto j:mp){
	 	float groupSize=j.first;
	 	float reportees=j.second;
	 	int totalPerColor=ceil(reportees/groupSize);
	 	totalSum+=totalPerColor*groupSize;
	 }
	return totalSum;
}

int main(){
	int arr[] ={2,2,0};
	int n=sizeof(arr)/sizeof(arr[0]);
	int ans=countRabbits(arr,n);
	cout<<ans;
	return 0;
}