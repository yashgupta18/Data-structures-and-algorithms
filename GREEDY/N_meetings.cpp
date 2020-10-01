#include<iostream>
#include<vector>
using namespace std;

struct meeting{
	int starting;
	int finishing;
	int pos;
};

void maxMeeting(int s[], int f[], int n){

	struct meeting meet[n];

	for (int i = 0; i < n; ++i)
	{
		meet[i].starting=s[i];
		meet[i].finishing=f[i];
		meet[i].pos=i+1;
	}

	vector<int> result;

	//initially push first pair position
	result.push_back(meet[0].pos);
	//ending time for previos meeting
	int prev_end_time=meet[0].finishing;

	for (int i = 1; i < n; ++i)
	{	
		//compare starting time of current meeting with ending time of prev meeting
		if(meet[i].starting >= prev_end_time){
			result.push_back(meet[i].pos);
			prev_end_time=meet[i].finishing;
		}
	}
	//result printing
	cout<<"Positions:";
	for (int i = 0; i < result.size(); ++i)
	{
		cout<<result[i]<<" ";
	}
	return;
}

int main(){
	 // Starting time 
    int s[] = { 1, 3, 0, 5, 8, 5 };  
    // Finish time 
    int f[] = { 2, 4, 6, 7, 9, 9 };  
    // Number of meetings. 
    int n = sizeof(s) / sizeof(s[0]); 
    // Function call 
    maxMeeting(s, f, n); 
	return 0;
}