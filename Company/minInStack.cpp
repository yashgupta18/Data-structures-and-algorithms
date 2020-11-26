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

class MinStack {
  
public:
    /** initialize your data structure here. */
    stack<int>s;
    stack<int>ss;
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(ss.size()==0 || ss.top()>=x){
            ss.push(x);
            return;
        }
        
    }
    
    void pop() {
        if(s.size()==0){
            return ;
        }
        int ans= s.top();
        s.pop();
            if(ss.top()==ans){
                ss.pop();
            }
        // return ans;
    }
    
    int top() {
        if(s.size()==0){
            return -1;
        }
        return s.top();
    }
    
    int getMin() {
        if(ss.size()==0){
            return -1;
        }
        return ss.top();
    }
};

// Driver function 
// int main() 
// { 
// 	stack<int> s;
// 	int arr[]={10,1,21,45,2,34};
// 	int n=sizeof(arr)/sizeof(arr[0]);
// 	stack<int> s1;
// 	stack<int> s2;
// 	pushInStack(10, s1, s2);
// 	pushInStack(1, s1, s2);
// 	pushInStack(34, s1, s2);
// 	 pushInStack(12, s1, s2);


//     while(!s2.empty()){
//     	cout<<s2.top()<<endl;
//     	s2.pop();
//     }


//     return 0; 



// } 