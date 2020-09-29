#include <iostream>
#include<vector>
#include<stack>

using namespace std;

void stack_pop(stack<int> &s, int k){

	// if (size==0)
	// {
	// 	// cout<<"Can't find middle";
	// 	return ;
	// }
	
	 if (k==1)
	 {
	 	s.pop();
	 	return;
	 }

	 int temp=s.top();
	 s.pop();
	 stack_pop(s, k-1);
	 s.push(temp); 
	 

	 return;
}

// void Sort(vector<int> &v){

// 	if (v.size()<=1)
// 	{
// 		return ;
// 	}

// 	int temp=v.size()-1;
// 	v.pop_back();
// 	insert(v,temp);
// }





int main(){
	int n=4;
	// vector<int> v;

 //    v.push_back(8);
 //    v.push_back(67);
 //    v.push_back(34);
 //    v.push_back(69);

	stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    // int k=3;
   int k=(s.size()/2) +1;
	stack_pop(s,k);
	while(s.size()!=0){
   		cout<<s.top();
   		s.pop();
   	}
	return 0;
}