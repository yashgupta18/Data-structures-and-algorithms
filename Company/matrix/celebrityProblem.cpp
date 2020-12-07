#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;

// #define N 8 
  
// // Person with 2 is celebrity 
// bool MATRIX[N][N] = {{0, 0, 1, 0}, 
//                     {0, 0, 1, 0}, 
//                     {0, 0, 0, 0}, 
//                     {0, 0, 1, 0}}; 


// int checkCelebrity(stack<int> s, int n){
// 	while(s.size()>1){
// 		int top1=s.top();
// 		s.pop();
// 		int top2=s.top();
// 		s.pop();

// 		if(MATRIX[top1][top2]){
// 			s.push(top2);
// 		}else{
// 			s.push(top1);
// 		}
// 	}

// 	//last element left in stack
// 	int lastTop=s.top();
// 	s.pop();
// 	for (int i = 0; i < n; ++i)
// 	{
// 		if(i!=lastTop){
// 			if(MATRIX[lastTop][i]==1 || MATRIX[i][lastTop]==0){
// 				return 0;
// 			}
// 		}
// 	}

// 	return lastTop;
// }


// int main(){

// stack<int> s;
// s.push(0);
// s.push(1);
// s.push(2);
// s.push(3);

// int ans=checkCelebrity(s, 4);
// cout<<ans;
// return 0;

// } 


// 2 pointer approach
//very simialr to stack.keep eliminating a row at a time
#define N 8 
  
// Person with 2 is celebrity 
bool MATRIX[N][N] = {{0, 0, 1, 0}, 
                    {0, 0, 1, 0}, 
                    {0, 0, 0, 0}, 
                    {0, 0, 1, 0}}; 


int knows(int a, int b){
	return MATRIX[a][b];
}

int checkCelebrity(int n){
	int a=0, b=n-1;
	while(a<b){
		if(knows(a,b)){
			a++;
		}
		else{
			b--;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if(a!=i){
			if(knows(a,i) || !knows(i,a)){
				return 0;
			}
		}
	}
	return a;
}


int main(){
int n=4;
int ans=checkCelebrity(n);
cout<<ans;
return 0;

} 
