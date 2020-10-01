#include<iostream>
#include<vector>
using namespace std;

struct Job{
	char id;
	int deadline;
	int profit;
};

bool compare(Job job1, Job job2){
	return (job1.profit>job2.profit) ;
}

void printJobScheduling(Job arr[], int n){

	sort(arr, arr+n, compare);

	char result[n];
	bool slot[n];

	for (int i = 0; i < n; ++i)
	{
		slot[i]=false;
	}

	for (int i = 0; i < n; ++i)
	{
		//start from end.
		for (int j = min(n, arr[i].deadline)-1; j>=0; --j)
		{
			//if free slot add it to result
			if(slot[j]==false){
				result[j]=arr[i].id;
				slot[j]=true;
				break;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if(slot[i]){
			cout<<result[i]<<" ";
		}
		
	}
	return;
}

int main(){
	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
                   {'d', 1, 25}, {'e', 3, 15}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Following is maximum profit sequence of job"<<endl; 
    printJobScheduling(arr, n); 
	return 0;
}