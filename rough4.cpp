// APPLES
#include <iostream>
#include <vector>

using namespace std;  


// Driver program to test above function
int main()
{
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(3);
	for(int i:coins){
		cout<<i<<" ";
	}
	return 0;
}
