#include<iostream>
#include<vector>
using namespace std;

struct Knapsack{
	int value;
	int weight;
};

bool compare(Knapsack sack1, Knapsack sack2){
	int p1=sack1.value/sack1.weight;
	int p2=sack2.value/sack2.weight;

	return p1>p2;
}

void fractionalKnapsack(Knapsack arr[], int n, int capacity){

	sort(arr, arr+n, compare);
	int profit=0;
	int remain=capacity;
	// char result[n];
	// bool slot[n];

	for (int i = 0; i < n; ++i)
	{
		if(arr[i].weight<=capacity){
			profit=profit + arr[i].value;
			capacity=capacity - arr[i].weight;
		}
		else{
			int temp= ((double)capacity/arr[i].weight) * (arr[i].value);
			profit=profit+temp;
			break;
		}
	}
	cout<<"Max Profit="<<profit;
	return;
}

int main(){
	Knapsack arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
	int capacity=50;
    int n = sizeof(arr)/sizeof(arr[0]); 
    fractionalKnapsack(arr, n,capacity); 
	return 0;
}