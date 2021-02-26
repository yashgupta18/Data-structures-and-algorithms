#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    int n= popped.size();
     // maintain count of popped elements 
    int j = 0; 
      
    // an empty stack 
    stack <int> st; 
    for(int i = 0; i < n; i++){ 
        st.push(pushed[i]); 
          
        // check if appended value is next to be popped out 
        while (!st.empty() && j < n && st.top() == popped[j]){ 
            st.pop(); 
            j++; 
        } 
    } 
      
    if(j==n) return true;
    return false; 
}

// https://www.geeksforgeeks.org/check-if-the-given-push-and-pop-sequences-of-stack-is-valid-or-not/
int main(){
	vector<int> pushed;
	pushed.push_back(0);
	pushed.push_back(2);
	pushed.push_back(1);

	vector<int> popped;
	popped.push_back(0);
	popped.push_back(1);
	popped.push_back(2);
	cout<<validateStackSequences(pushed, popped);
}