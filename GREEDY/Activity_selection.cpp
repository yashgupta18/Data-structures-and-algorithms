#include<iostream>
#include<vector>
using namespace std;

struct Activity{
	int stime;
	int ftime;
};

bool compare(Activity act1, Activity act2){
	return act1.ftime<act2.ftime;
}

void activity_selection(Activity arr[], int n){

	sort(arr, arr+n, compare);
	vector<pair<int,int> > result;
	int temp=arr[0].ftime;
	result.push_back(make_pair(arr[0].stime, arr[0].ftime));
	for (int i = 1; i < n; ++i)
	{	
		// if start time of next is greater than finish time of first make pair and insert in result
		if(arr[i].stime>temp){
			result.push_back(make_pair(arr[i].stime, arr[i].ftime));
			temp=arr[i].ftime;
		}	
	}

	for (auto it:result)
	{
		cout<<it.first<<" "<<it.second;
		cout<<endl;
	}
	
	return;
}

int main(){
	Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    activity_selection(arr, n); 
	return 0;
}

