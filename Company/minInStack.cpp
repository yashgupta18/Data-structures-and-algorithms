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

  stack<int>s;
    int min;
    MinStack() {
        
    }
    
    void push(int x) {
        if(s.size()==0){
            s.push(x);
            min=x;
        }
        else{
            if(x>min){
                s.push(x);
            }
            else if(x<min){
                int y=2*x-min;
                min= x;
                s.push(y);
            }
        }
        return;
        }
        
    
    
    void pop() {
        if(s.size()==0){
            return ;
        }
        else if(s.top()>=min)
            s.pop();
        
        else if(s.top()<min){
            min=2*min-s.top();
                s.pop();
               
            }
        // return ans;
    }
    
    int top() {
        if(s.size()==0){
            return -1;
        }
        else{
            if(s.top()>=min)
                return s.top();
            else if(s.top()<min)
                return min;
        }  
    }
    
    int getMin() {
        if(ss.size()==0){
            return -1;
        }
        
        return min;
    }

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