#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

int paintFence(int n, int c){
    //this problem initially for min n=2.So calculate same and diff for n=2
    int same=c*1;
    int diff=c*(c-1);
    // then from 3 to n calculate using prev same and diff
    for (int i = 3; i < n; ++i)
    {
       same=diff*1;
       diff=same+diff;
    }
    return same+diff;
	
}


int main(){
	int n=2;
    int c=4;
	cout<<paintFence(n, c);
	return 0;
}







