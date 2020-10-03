#include<iostream>
#include<vector>
using namespace std;


void findPlatform(int arr[], int dep[], int n){
	sort(arr, arr+n);
	sort(dep, dep+n);
	int platformsneeded=1;
	int i=1;
	int j=0;
	while(i<n && j<n){
		if(arr[i]<=dep[j]){
			platformsneeded++;
			i++;
		}
		else {
			i++;
			j++;
		}
	}
	cout<<platformsneeded;
}






int main() 
{ 
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    findPlatform(arr, dep, n); 
    return 0; 
} 